class Solution {
    public static String smallestWindow(String s, String p) {
        int m = s.length(), n = p.length();
        if (m < n) return "";
        int[] need = new int[256];
        for (char c : p.toCharArray()) need[c]++;
        int missing = n, start = 0, minStart = 0, minLen = Integer.MAX_VALUE;
        for (int end = 0; end < m; end++) {
            if (need[s.charAt(end)]-- > 0) missing--;
            while (missing == 0) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                if (++need[s.charAt(start++)] > 0) missing++;
            }
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
}
