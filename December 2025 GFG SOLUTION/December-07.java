class Solution {
    int distinctSubseq(String str) {
        int n = str.length(), mod = 1000000007, res = 1;
        int[] last = new int[26];
        for (int i = 0; i < n; i++) {
            int idx = str.charAt(i) - 'a';
            int cur = (int)((2L * res % mod - last[idx] + mod) % mod);
            last[idx] = res;
            res = cur;
        }
        return res;
    }
}
