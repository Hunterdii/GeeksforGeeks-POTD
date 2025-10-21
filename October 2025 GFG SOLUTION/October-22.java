class Solution {
    public ArrayList<Integer> topKFreq(int[] a, int k) {
        HashMap<Integer, Integer> f = new HashMap<>();
        for (int x : a) f.put(x, f.getOrDefault(x, 0) + 1);
        List<int[]> v = new ArrayList<>();
        for (var e : f.entrySet()) v.add(new int[]{e.getValue(), e.getKey()});
        v.sort((x, y) -> y[0] == x[0] ? y[1] - x[1] : y[0] - x[0]);
        ArrayList<Integer> r = new ArrayList<>();
        for (int i = 0; i < k; i++) r.add(v.get(i)[1]);
        return r;
    }
}
