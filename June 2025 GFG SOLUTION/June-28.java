class Solution {
    public static ArrayList<Integer> countLessEq(int[] a, int[] b) {
        int max = 0;
        for (int x : b) max = Math.max(max, x);
        int[] cnt = new int[max + 1];
        for (int x : b) cnt[x]++;
        for (int i = 1; i <= max; i++) cnt[i] += cnt[i - 1];
        ArrayList<Integer> res = new ArrayList<>();
        for (int x : a) res.add(cnt[Math.min(x, max)]);
        return res;
    }
}
