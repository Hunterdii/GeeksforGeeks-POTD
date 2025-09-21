class Solution {
    static int maxArea(int mat[][]) {
        int n = mat.length, m = mat[0].length, res = 0;
        int[] h = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = mat[i][j] == 1 ? h[j] + 1 : 0;
            Stack<Integer> st = new Stack<>();
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!st.isEmpty() && h[st.peek()] > cur) {
                    int tp = st.pop();
                    int w = st.isEmpty() ? j : j - st.peek() - 1;
                    res = Math.max(res, h[tp] * w);
                }
                st.push(j);
            }
        }
        return res;
    }
}
