class Solution {
    public ArrayList<ArrayList<Integer>> kClosest(int[][] points, int k) {
        Arrays.sort(points, (a, b) -> (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]));
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        for (int i = 0; i < k; i++)
            res.add(new ArrayList<>(Arrays.asList(points[i][0], points[i][1])));
        return res;
    }
}
