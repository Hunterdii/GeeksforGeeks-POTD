class Solution {
    public int minCostPath(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});
        dist[0][0] = 0;
        int[] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0], x = curr[1], y = curr[2];
            if (x == n - 1 && y == m - 1) return d;
            if (d > dist[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = Math.max(d, Math.abs(mat[nx][ny] - mat[x][y]));
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        pq.offer(new int[]{nd, nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
}
