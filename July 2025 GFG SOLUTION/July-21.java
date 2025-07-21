class Solution {
    int cntCoprime(int[] arr) {
        int mx = Arrays.stream(arr).max().orElse(0);
        int[] cnt = new int[mx + 1], div = new int[mx + 1], mu = new int[mx + 1];
        boolean[] vis = new boolean[mx + 1];
        
        for (int x : arr) cnt[x]++;
        
        Arrays.fill(mu, 1);
        for (int i = 2; i <= mx; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= mx; j += i) {
                    mu[j] *= -1;
                    vis[j] = true;
                }
                for (long j = (long)i * i; j <= mx; j += (long)i * i)
                    mu[(int)j] = 0;
            }
        }
        
        for (int i = 1; i <= mx; ++i)
            for (int j = i; j <= mx; j += i)
                div[i] += cnt[j];
        
        int ans = 0;
        for (int i = 1; i <= mx; ++i)
            if (mu[i] != 0 && div[i] > 1)
                ans += mu[i] * div[i] * (div[i] - 1) / 2;
        
        return ans;
    }
}
