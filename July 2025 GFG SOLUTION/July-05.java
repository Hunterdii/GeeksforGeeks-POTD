class Solution {
    public int maxSum(int arr[]) {
        int ans = 0;
        for (int i = 1; i < arr.length; i++)
            ans = Math.max(arr[i] + arr[i - 1], ans);
        return ans;
    }
}
