class Solution {
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        ArrayList<ArrayList<Integer>> dist = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            dist.add(new ArrayList<>());
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist.get(i).add(0);
                    q.offer(new int[]{i, j});
                } else dist.get(i).add(-1);
            }
        }
        int[] dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist.get(nx).get(ny) == -1) {
                    dist.get(nx).set(ny, dist.get(x).get(y) + 1);
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        return dist;
    }
}
