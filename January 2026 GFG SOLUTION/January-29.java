class Solution {
    public String firstNonRepeating(String s) {
        int[] freq = new int[26];
        Queue<Character> q = new LinkedList<>();
        StringBuilder res = new StringBuilder();
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
            q.add(c);
            while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) q.poll();
            res.append(q.isEmpty() ? '#' : q.peek());
        }
        return res.toString();
    }
}
