class Solution {
public:
    int countNumbers(int n) {
        int c = 0, lim = sqrt(n);
        vector<int> spf(lim + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= lim; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= lim; j += i)
                    if (spf[j] == j) spf[j] = i;
        for (int i = 2; i <= lim; ++i) {
            int p = spf[i], q = spf[i / p];
            if (p * q == i && p != q && q != 1) ++c;
            else if (spf[i] == i && pow(i, 8) <= n) ++c;
        }
        return c;
    }
};
