class Solution {
    public String minWindow(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int start = -1, minLen = Integer.MAX_VALUE;
        for (int i = 0, j = 0; i < m; i++) {
            if (s1.charAt(i) == s2.charAt(j)) j++;
            if (j == n) {
                int end = i;
                j--;
                while (j >= 0) {
                    if (s1.charAt(i) == s2.charAt(j)) j--;
                    i--;
                }
                i++;
                j++;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }
        return start == -1 ? "" : s1.substring(start, start + minLen);
    }
}
