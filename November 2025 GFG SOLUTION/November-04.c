int minCost(int height[], int n) {
    if (n == 1) return 0;
    int a = 0, b = abs(height[1] - height[0]);
    for (int i = 2; i < n; i++) {
        int c = (b + abs(height[i] - height[i - 1]) < a + abs(height[i] - height[i - 2])) ? 
                b + abs(height[i] - height[i - 1]) : a + abs(height[i] - height[i - 2]);
        a = b;
        b = c;
    }
    return b;
}
