class Solution {
    public int countStrings(String s) {
        int[] m = new int[26];
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans += i - m[s.charAt(i) - 'a'];
            ++m[s.charAt(i) - 'a'];
        }
        for (int x : m) if (x > 1) { ans++; break; }
        return ans;
    }
}
