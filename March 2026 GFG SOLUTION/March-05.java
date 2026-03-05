class Solution {
    public int longestKSubstr(String s, int k) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int l = 0, res = -1;
        for (int r = 0; r < s.length(); r++) {
            mp.put(s.charAt(r), mp.getOrDefault(s.charAt(r), 0) + 1);
            while (mp.size() > k) {
                mp.put(s.charAt(l), mp.get(s.charAt(l)) - 1);
                if (mp.get(s.charAt(l)) == 0) mp.remove(s.charAt(l));
                l++;
            }
            if (mp.size() == k) res = Math.max(res, r - l + 1);
        }
        return res;
    }
}
