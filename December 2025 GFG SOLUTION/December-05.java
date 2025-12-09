class Solution {
    int minCost(int[][] costs) {
        int n = costs.length, m = costs[0].length;
        if (m == 1 && n > 1) return -1;
        int m1 = 0, m2 = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            int nm1 = Integer.MAX_VALUE, nm2 = Integer.MAX_VALUE, nidx = -1;
            for (int j = 0; j < m; j++) {
                int c = costs[i][j] + (j == idx ? m2 : m1);
                if (c < nm1) { nm2 = nm1; nm1 = c; nidx = j; }
                else if (c < nm2) nm2 = c;
            }
            m1 = nm1; m2 = nm2; idx = nidx;
        }
        return m1;
    }
}
