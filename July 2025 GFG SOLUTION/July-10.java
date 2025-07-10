class Solution {
    public String longestString(String[] words) {
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        Set<String> st = new HashSet<>();
        String res = "";
        for (String w : words) {
            if (w.length() == 1 || st.contains(w.substring(0, w.length() - 1))) {
                st.add(w);
                if (w.length() > res.length() || (w.length() == res.length() && w.compareTo(res) < 0)) {
                    res = w;
                }
            }
        }
        return res;
    }
}
