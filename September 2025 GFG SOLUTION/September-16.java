class Solution {
    public int evaluatePostfix(String[] arr) {
        Stack<Integer> st = new Stack<>();
        for (String t : arr) {
            if (t.length() == 1 && "+-*/^".contains(t)) {
                int b = st.pop(), a = st.pop();
                if (t.equals("/")) st.push((a < 0) ^ (b < 0) && a % b != 0 ? a / b - 1 : a / b);
                else st.push(t.equals("+") ? a + b : t.equals("-") ? a - b : 
                           t.equals("*") ? a * b : (int)Math.pow(a, b));
            } else st.push(Integer.parseInt(t));
        }
        return st.peek();
    }
}
