class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
        Arrays.sort(x); Arrays.sort(y);
        int h = 1, v = 1, i = x.length - 1, j = y.length - 1, cost = 0;
        while (i >= 0 && j >= 0) {
            if (x[i] > y[j]) { cost += x[i--] * h; v++; }
            else { cost += y[j--] * v; h++; }
        }
        while (i >= 0) cost += x[i--] * h;
        while (j >= 0) cost += y[j--] * v;
        return cost;
    }
}
