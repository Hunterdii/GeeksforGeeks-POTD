class Solution {
    int minCost(int[] height) {
        int n = height.length;
        if (n == 1) return 0;
        int a = 0, b = Math.abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            int c = Math.min(b + Math.abs(height[i] - height[i - 1]), 
                            a + Math.abs(height[i] - height[i - 2]));
            a = b;
            b = c;
        }
        return b;
    }
}
