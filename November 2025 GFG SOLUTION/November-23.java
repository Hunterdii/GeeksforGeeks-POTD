class Solution {
    int maxRemove(int[][] stones) {
        int n = stones.length;
        int[] p = new int[20002];
        Arrays.fill(p, -1);
        for (int[] s : stones) union(s[0], s[1] + 10001, p);
        Set<Integer> roots = new HashSet<>();
        for (int[] s : stones) roots.add(find(s[0], p));
        return n - roots.size();
    }
    int find(int x, int[] p) {
        return p[x] < 0 ? x : (p[x] = find(p[x], p));
    }
    void union(int x, int y, int[] p) {
        x = find(x, p); y = find(y, p);
        if (x != y) p[x] = y;
    }
}
