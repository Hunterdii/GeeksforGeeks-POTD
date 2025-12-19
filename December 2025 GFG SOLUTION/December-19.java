class Solution {
    public int findMoves(int[] c, int[] p) {
        Arrays.sort(c);
        Arrays.sort(p);
        int res = 0;
        for (int i = 0; i < c.length; i++) res += Math.abs(c[i] - p[i]);
        return res;
    }
}
