int minSuperSeq(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int prev[n + 1], curr[n + 1];
    for (int j = 0; j <= n; j++) prev[j] = j;
    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            curr[j] = (s1[i - 1] == s2[j - 1]) ? 1 + prev[j - 1] : 
                      1 + (prev[j] < curr[j - 1] ? prev[j] : curr[j - 1]);
        }
        for (int j = 0; j <= n; j++) prev[j] = curr[j];
    }
    return prev[n];
}
