class Solution {
    public int secondMST(int V, int[][] edges) {
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        int[] p = new int[V], r = new int[V];
        for (int i = 0; i < V; i++) p[i] = i;
        int mst = 0, ans = Integer.MAX_VALUE;
        List<int[]> tree = new ArrayList<>();
        for (int[] e : edges) {
            int a = find(p, e[0]), b = find(p, e[1]);
            if (a != b) {
                if (r[a] < r[b]) { int t = a; a = b; b = t; }
                p[b] = a;
                if (r[a] == r[b]) r[a]++;
                mst += e[2];
                tree.add(e);
            }
        }
        for (int[] skip : tree) {
            for (int i = 0; i < V; i++) { p[i] = i; r[i] = 0; }
            int cost = 0, cnt = 0;
            for (int[] e : edges) {
                if ((e[0] == skip[0] && e[1] == skip[1]) || (e[0] == skip[1] && e[1] == skip[0])) continue;
                int a = find(p, e[0]), b = find(p, e[1]);
                if (a != b) {
                    if (r[a] < r[b]) { int t = a; a = b; b = t; }
                    p[b] = a;
                    if (r[a] == r[b]) r[a]++;
                    cost += e[2];
                    if (++cnt == V - 1) break;
                }
            }
            if (cnt == V - 1 && cost > mst) ans = Math.min(ans, cost);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
    int find(int[] p, int x) { return p[x] == x ? x : (p[x] = find(p, p[x])); }
}
