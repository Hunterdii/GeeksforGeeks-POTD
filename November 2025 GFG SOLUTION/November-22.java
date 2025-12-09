class Solution {
    public int minConnect(int V, int[][] edges) {
        int comp = V, e = edges.length;
        if (e < V - 1) return -1;
        int[] p = new int[V];
        for (int i = 0; i < V; i++) p[i] = i;
        for (int[] ed : edges) {
            int x = find(p, ed[0]), y = find(p, ed[1]);
            if (x != y) { p[x] = y; --comp; }
        }
        return comp - 1;
    }
    int find(int[] p, int x) { 
       return p[x] == x ? x : (p[x] = find(p, p[x])); 
    }
}
