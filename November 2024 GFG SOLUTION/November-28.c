//{ Driver Code Starts
#include <limits.h>
#include <stdio.h>


// } Driver Code Ends
// User function Template for C
int myAtoi(char *s) {
    int idx = 0, sign = 1;
    long res = 0;

    while (s[idx] == ' ') idx++;

    if (s[idx] == '-' || s[idx] == '+') {
        sign = (s[idx++] == '-') ? -1 : 1;
    }

    while (s[idx] >= '0' && s[idx] <= '9') {
        res = res * 10 + (s[idx++] - '0');

        if (res * sign > INT_MAX) return INT_MAX;
        if (res * sign < INT_MIN) return INT_MIN;
    }

    return (int)(res * sign);
}


//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char s[20];
        scanf("%s", s);
        int ans = myAtoi(s);
        printf("%d\n~\n", ans);
    }
}
// } Driver Code Ends
