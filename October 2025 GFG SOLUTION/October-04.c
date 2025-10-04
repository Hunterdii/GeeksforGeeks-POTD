char** findExpr(char* s, int target, int* returnSize) {
    int cap = 1000, cnt = 0, len = strlen(s);
    char** res = malloc(cap * sizeof(char*));
    void dfs(int i, long val, long prev, char* path, int plen) {
        if (i == len) {
            if (val == target) {
                res[cnt] = malloc(plen + 1);
                strcpy(res[cnt++], path);
                if (cnt == cap) res = realloc(res, (cap *= 2) * sizeof(char*));
            }
            return;
        }
        for (int j = i; j < len; j++) {
            if (j > i && s[i] == '0') break;
            long cur = 0;
            for (int k = i; k <= j; k++) cur = cur * 10 + (s[k] - '0');
            char num[20]; sprintf(num, "%ld", cur);
            int nlen = strlen(num);
            if (i == 0) {
                strcpy(path, num);
                dfs(j + 1, cur, cur, path, nlen);
            } else {
                path[plen] = '+'; strcpy(path + plen + 1, num);
                dfs(j + 1, val + cur, cur, path, plen + 1 + nlen);
                path[plen] = '-'; strcpy(path + plen + 1, num);
                dfs(j + 1, val - cur, -cur, path, plen + 1 + nlen);
                path[plen] = '*'; strcpy(path + plen + 1, num);
                dfs(j + 1, val - prev + prev * cur, prev * cur, path, plen + 1 + nlen);
            }
        }
    }
    char path[100];
    dfs(0, 0, 0, path, 0);
    *returnSize = cnt;
    return res;
}
