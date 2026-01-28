class Solution {
    public int countSubset(int[] arr, int k) {
        int n = arr.length, m = n / 2, res = 0;
        Map<Integer, Integer> lf = new HashMap<>(), rf = new HashMap<>();
        gen(arr, 0, m, 0, lf);
        gen(arr, m, n, 0, rf);
        for (var e : lf.entrySet()) res += e.getValue() * rf.getOrDefault(k - e.getKey(), 0);
        return res;
    }
    void gen(int[] arr, int i, int e, int s, Map<Integer, Integer> f) {
        if (i == e) { f.merge(s, 1, Integer::sum); return; }
        gen(arr, i + 1, e, s + arr[i], f);
        gen(arr, i + 1, e, s, f);
    }
}
