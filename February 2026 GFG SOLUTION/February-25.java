class Solution {
    public int longestSubarray(int[] arr, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int sum = 0, ans = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += (arr[i] > k) ? 1 : -1;
            if (sum > 0) ans = i + 1;
            else if (mp.containsKey(sum - 1)) ans = Math.max(ans, i - mp.get(sum - 1));
            if (!mp.containsKey(sum)) mp.put(sum, i);
        }
        return ans;
    }
}
