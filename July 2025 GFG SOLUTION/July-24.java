class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        int maxTime = 0;
        for (int p : left) maxTime = Math.max(maxTime, p);
        for (int p : right) maxTime = Math.max(maxTime, n - p);
        return maxTime;
    }
}

2)
class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int maxLeft = Arrays.stream(left).max().orElse(0);
        int maxRight = n - Arrays.stream(right).min().orElse(n);
        return Math.max(maxLeft, maxRight);
    }
}

3)
class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        int ans = 0;
        for (int x : left) ans = Math.max(ans, x);
        for (int x : right) ans = Math.max(ans, n - x);
        return ans;
    }
}
