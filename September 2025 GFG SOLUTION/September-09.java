class Solution {
    public int assignHole(int[] m, int[] h) {
        Arrays.sort(m);
        Arrays.sort(h);
        int r = 0;
        for (int i = 0; i < m.length; i++)
            r = Math.max(r, Math.abs(m[i] - h[i]));
        return r;
    }
}
