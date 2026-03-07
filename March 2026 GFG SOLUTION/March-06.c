#include <string.h>
#include <limits.h>

char* smallestWindow(char* s, char* p) {
    int n = strlen(s), m = strlen(p);
    if (n < m) return "";
    int fp[256] = {0}, fs[256] = {0};
    for (int i = 0; i < m; i++) fp[p[i]]++;
    int l = 0, cnt = 0, minLen = INT_MAX, start = -1;
    for (int r = 0; r < n; r++) {
        fs[s[r]]++;
        if (fp[s[r]] && fs[s[r]] <= fp[s[r]]) cnt++;
        while (cnt == m) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            fs[s[l]]--;
            if (fp[s[l]] && fs[s[l]] < fp[s[l]]) cnt--;
            l++;
        }
    }
    if (start == -1) return "";
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}
