class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        if (n < k || n > 9 * k) return res;
        backtrack(res, new ArrayList<>(), n, k, 1);
        return res;
    }
    
    void backtrack(ArrayList<ArrayList<Integer>> res, ArrayList<Integer> cur, int rem, int left, int start) {
        if (left == 0) {
            if (rem == 0) res.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (rem < i) break;
            cur.add(i);
            backtrack(res, cur, rem - i, left - 1, i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}
