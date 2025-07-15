class Solution {
    public boolean divby13(String s) {
        int r = 0;
        for (int i = 0; i < s.length(); ++i) {
            r = (r * 10 + s.charAt(i) - '0') % 13;
        }
        return r == 0;
    }
}
