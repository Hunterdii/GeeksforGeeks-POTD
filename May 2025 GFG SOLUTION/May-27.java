class Solution {
    public ArrayList<Integer> leafNodes(int[] p) {
        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> r = new ArrayList<>();
        for (int i = 0, j = 1; j < p.length; i++, j++) {
            boolean f = false;
            if (p[i] > p[j]) st.push(p[i]);
            else {
                while (!st.isEmpty() && p[j] > st.peek()) {
                    st.pop();
                    f = true;
                }
            }
            if (f) r.add(p[i]);
        }
        r.add(p[p.length-1]);
        return r;
    }
}
