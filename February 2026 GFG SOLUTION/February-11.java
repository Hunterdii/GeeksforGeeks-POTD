class Solution {
    public int minCost(int[] heights, int[] cost) {
        int n = heights.length;
        int[][] v = new int[n][2];
        for (int i = 0; i < n; i++) {
            v[i][0] = heights[i];
            v[i][1] = cost[i];
        }
        Arrays.sort(v, (a, b) -> a[0] - b[0]);
        long total = 0;
        for (int x : cost) total += x;
        long sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i][1];
            if (sum >= (total + 1) / 2) {
                for (int j = 0; j < n; j++) res += (long)Math.abs(heights[j] - v[i][0]) * cost[j];
                return (int)res;
            }
        }
        return 0;
    }
}
