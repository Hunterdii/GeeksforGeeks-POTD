class Solution {
    public int subarraySum(int[] arr) {
        int n = arr.length, sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i] * (i + 1) * (n - i);
        return sum;
    }
}
