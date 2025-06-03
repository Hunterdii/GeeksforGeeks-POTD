class Solution {
    int count(String s, int k) {
        int[] freq = new int[26];
        int i = 0, ans = 0, distinct = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (++freq[s.charAt(j) - 'a'] == 1) ++distinct;
            while (distinct > k)
                if (--freq[s.charAt(i++) - 'a'] == 0) --distinct;
            ans += j - i + 1;
        }
        return ans;
    }

    int countSubstr(String s, int k) {
        return count(s, k) - count(s, k - 1);
    }
}
