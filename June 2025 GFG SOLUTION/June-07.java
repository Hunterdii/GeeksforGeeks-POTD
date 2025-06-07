class Solution {
    public int longestCommonSum(int[] arr1, int[] arr2) {
        int n = arr1.length, sum1 = 0, sum2 = 0, res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            sum1 += arr1[i];
            sum2 += arr2[i];
            int diff = sum1 - sum2;
            if (diff == 0)
                res = i + 1;
            else if (map.containsKey(diff))
                res = Math.max(res, i - map.get(diff));
            else
                map.put(diff, i);
        }
        return res;
    }
}
