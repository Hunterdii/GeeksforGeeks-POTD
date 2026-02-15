class Solution {
    public int findMinDiff(ArrayList<Integer> a, int m) {
        Collections.sort(a);
        int res = Integer.MAX_VALUE;
        for (int i = 0; i + m <= a.size(); i++)
            res = Math.min(res, a.get(i + m - 1) - a.get(i));
        return res;
    }
}
