class Solution {
    public ArrayList<Integer> findOrder(int n, int[][] pre) {
        ArrayList<ArrayList<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) g.add(new ArrayList<>());
        int[] d = new int[n];
        for (int[] p : pre) g.get(p[1]).add(p[0]); 
        for (int[] p : pre) d[p[0]]++;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (d[i] == 0) q.add(i);
        ArrayList<Integer> r = new ArrayList<>();
        while (!q.isEmpty()) {
            int u = q.poll(); r.add(u);
            for (int v : g.get(u)) if (--d[v] == 0) q.add(v);
        }
        return r.size() == n ? r : new ArrayList<>();
    }
}
