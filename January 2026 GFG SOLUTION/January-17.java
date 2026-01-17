class Solution {
    public boolean checkRedundancy(String s) {
        java.util.Stack<Character> st = new java.util.Stack<>();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                boolean op = false;
                while (st.peek() != '(') {
                    char t = st.pop();
                    if (t == '+' || t == '-' || t == '*' || t == '/') op = true;
                }
                st.pop();
                if (!op) return true;
            } else if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/') {
                st.push(c);
            }
        }
        return false;
    }
}
