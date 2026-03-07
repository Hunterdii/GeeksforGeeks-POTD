class Solution {
    public static String minWindow(String s, String p) {
        int n = s.length(), m = p.length();
        if (n < m) return "";
        int[] fp = new int[256], fs = new int[256];
        for (char c : p.toCharArray()) fp[c]++;
        int l = 0, cnt = 0, minLen = Integer.MAX_VALUE, start = -1;
        for (int r = 0; r < n; r++) {
            fs[s.charAt(r)]++;
            if (fp[s.charAt(r)] > 0 && fs[s.charAt(r)] <= fp[s.charAt(r)]) cnt++;
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                fs[s.charAt(l)]--;
                if (fp[s.charAt(l)] > 0 && fs[s.charAt(l)] < fp[s.charAt(l)]) cnt--;
                l++;
            }
        }
        return start == -1 ? "" : s.substring(start, start + minLen);
    }
}
