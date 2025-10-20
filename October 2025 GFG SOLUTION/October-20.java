class Solution {
    public ArrayList<Integer> countBSTs(int[] arr) {
        int n = arr.length;
        int[][] p = new int[n][2];
        for (int i = 0; i < n; i++) {
            p[i][0] = arr[i];
            p[i][1] = i;
        }
        Arrays.sort(p, (a, b) -> a[0] - b[0]);
        long[] c = new long[n + 1];
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) 
                c[i] += c[j] * c[i - j - 1];
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) res.add(0);
        for (int i = 0; i < n; i++) 
            res.set(p[i][1], (int)(c[i] * c[n - i - 1]));
        return res;
    }
}
