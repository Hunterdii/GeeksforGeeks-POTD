class Solution {
    int getLPSLength(String s) {
        int n = s.length(), j = 0;
        int[] lps = new int[n];
        for (int i = 1; i < n; ) {
            if (s.charAt(i) == s.charAt(j)) lps[i++] = ++j;
            else if (j > 0) j = lps[j - 1];
            else i++;
        }
        return lps[n - 1];
    }
}
