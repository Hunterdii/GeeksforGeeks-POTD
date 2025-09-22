class Solution {
    public ArrayList<Integer> maxOfMins(int[] a) {
        int n = a.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int[] mx = new int[n + 1];
        Stack<Integer> st = new Stack<>();
        
        for (int i = 0; i <= n; i++) {
            while (!st.isEmpty() && (i == n || a[st.peek()] >= a[i])) {
                int mid = st.pop();
                int w = i - (st.isEmpty() ? -1 : st.peek()) - 1;
                mx[w] = Math.max(mx[w], a[mid]);
            }
            st.push(i);
        }
        
        for (int i = 1; i <= n; i++) ans.add(mx[i]);
        for (int i = n - 2; i >= 0; i--) {
            ans.set(i, Math.max(ans.get(i), ans.get(i + 1)));
        }
        return ans;
    }
}
