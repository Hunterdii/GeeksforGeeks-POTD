class Solution {
    public boolean isSubSeq(String s1, String s2) {
        int i = 0, n = s1.length(), m = s2.length();
        
        for (int j = 0; j < m && i < n; j++) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i++;
            }
        }
        return i == n;
    }
}
