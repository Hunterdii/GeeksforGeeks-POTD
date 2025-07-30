class Solution {
    public int cntSubarrays(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0, count = 0;
        map.put(0, 1);
        for (int num : arr) {
            sum += num;
            count += map.getOrDefault(sum - k, 0);
            map.merge(sum, 1, Integer::sum);
        }
        return count;
    }
}
