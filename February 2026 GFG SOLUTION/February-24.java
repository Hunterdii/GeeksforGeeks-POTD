class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);
        int diff = 0, maxLen = 0;
        for (int i = 0; i < a1.length; i++) {
            diff += a1[i] - a2[i];
            if (mp.containsKey(diff)) maxLen = Math.max(maxLen, i - mp.get(diff));
            else mp.put(diff, i);
        }
        return maxLen;
    }
}
