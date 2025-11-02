class Solution {
    public int maxEdgesToAdd(int V, int[][] edges) {
        return V * (V - 1) / 2 - edges.length;
    }
}
