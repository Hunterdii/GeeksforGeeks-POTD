class Solution {
    public ArrayList<Integer> largestSubset(int[] arr) {
        int n = arr.length;
        Integer[] temp = new Integer[n];
        for (int i = 0; i < n; i++) temp[i] = arr[i];
        Arrays.sort(temp, Collections.reverseOrder());
        
        int[] dp = new int[n];
        int[] parent = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(parent, -1);
        
        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (temp[j] % temp[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = maxIdx; i != -1; i = parent[i]) {
            result.add(temp[i]);
        }
        return result;
    }
}
