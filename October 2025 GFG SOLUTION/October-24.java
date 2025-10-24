class Solution {
    public boolean isPossible(int[] a, int k) {
        Map<Integer,Integer> freq = new HashMap<>(), need = new HashMap<>();
        for (int x : a) freq.put(x, freq.getOrDefault(x, 0) + 1);
        for (int x : a) {
            if (freq.get(x) == 0) continue;
            freq.put(x, freq.get(x) - 1);
            if (need.getOrDefault(x, 0) > 0) {
                need.put(x, need.get(x) - 1);
                need.put(x + 1, need.getOrDefault(x + 1, 0) + 1);
            } else {
                for (int i = 1; i < k; i++) {
                    if (freq.getOrDefault(x + i, 0) <= 0) return false;
                    freq.put(x + i, freq.get(x + i) - 1);
                }
                need.put(x + k, need.getOrDefault(x + k, 0) + 1);
            }
        }
        return true;
    }
}
