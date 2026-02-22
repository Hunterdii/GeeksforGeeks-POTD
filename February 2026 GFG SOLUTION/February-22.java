class Solution {
    public long subarrayXor(int arr[], int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int xorSum = 0;
        long cnt = 0;
        mp.put(0, 1);
        for (int x : arr) {
            xorSum ^= x;
            cnt += mp.getOrDefault(xorSum ^ k, 0);
            mp.put(xorSum, mp.getOrDefault(xorSum, 0) + 1);
        }
        return cnt;
    }
}
