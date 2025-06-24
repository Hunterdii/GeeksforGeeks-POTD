class Solution {
    public static String maxSubseq(String s, int k) {
        int n = s.length(), toRemove = k;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            while (toRemove > 0 && res.length() > 0 && res.charAt(res.length() - 1) < s.charAt(i)) {
                res.deleteCharAt(res.length() - 1);
                toRemove--;
            }
            res.append(s.charAt(i));
        }
        res.setLength(n - k);
        return res.toString();
    }
}
