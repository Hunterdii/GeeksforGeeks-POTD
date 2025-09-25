char** generate(int n) {
    char** res = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        int num = i + 1, len = 0, temp = num;
        while (temp) { len++; temp /= 2; }
        res[i] = malloc((len + 1) * sizeof(char));
        res[i][len] = '\0';
        for (int j = len - 1; j >= 0; j--) {
            res[i][j] = '0' + (num & 1);
            num >>= 1;
        }
    }
    return res;
}
