class Solution {
    public int minCost(int[] heights, int[] cost) {
        int l = 0, h = Arrays.stream(heights).max().getAsInt();
        while (l < h) {
            int m = l + (h - l) / 2;
            long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.length; ++i) {
                c1 += (long)Math.abs(heights[i] - m) * cost[i];
                c2 += (long)Math.abs(heights[i] - m - 1) * cost[i];
            }
            if (c1 <= c2) h = m;
            else l = m + 1;
        }
        long ans = 0;
        for (int i = 0; i < heights.length; ++i)
            ans += (long)Math.abs(heights[i] - l) * cost[i];
        return (int)ans;
    }
}
