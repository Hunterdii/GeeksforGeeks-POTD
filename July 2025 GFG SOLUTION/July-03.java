class Solution {
    public int longestKSubstr(String s, int k) {
        int[] freq = new int[26];
        int i = 0, cnt = 0, max = -1;
        for (int j = 0; j < s.length(); j++) {
            if (freq[s.charAt(j) - 'a']++ == 0) cnt++;
            while (cnt > k) {
                if (--freq[s.charAt(i) - 'a'] == 0) cnt--;
                i++;
            }
            if (cnt == k) max = Math.max(max, j - i + 1);
        }
        return max;
    }
}
