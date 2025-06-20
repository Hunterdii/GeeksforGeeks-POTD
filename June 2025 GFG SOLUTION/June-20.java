class Solution {
    public boolean validgroup(int[] arr, int k) {
        Map<Integer, Integer> m = new TreeMap<>();
        for (int x : arr) m.put(x, m.getOrDefault(x, 0) + 1);
        for (Map.Entry<Integer, Integer> e : m.entrySet()) {
            int v = e.getKey(), f = e.getValue();
            if (f == 0) continue;
            for (int i = 1; i < k; i++) {
                if (m.getOrDefault(v + i, 0) < f) return false;
                m.put(v + i, m.get(v + i) - f);
            }
        }
        return true;
    }
}
