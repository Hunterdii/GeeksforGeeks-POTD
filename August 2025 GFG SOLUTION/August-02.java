class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length, ans = 0, sum = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            sum += (arr[i] > k) ? 1 : -1;
            if (sum > 0) ans = i + 1;
            else if (mp.containsKey(sum - 1)) ans = Math.max(ans, i - mp.get(sum - 1));
            mp.putIfAbsent(sum, i);
        }
        return ans;
    }
}
