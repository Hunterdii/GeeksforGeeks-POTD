class Solution {
    public ArrayList<Integer> findMajority(int[] arr) {
        int n = arr.length, a = 0, b = 1, ca = 0, cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
            else if (ca == 0) { a = x; ca = 1; }
            else if (cb == 0) { b = x; cb = 1; }
            else { ca--; cb--; }
        }
        ca = cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
        }
        ArrayList<Integer> res = new ArrayList<>();
        if (ca > n / 3) res.add(a);
        if (cb > n / 3 && a != b) res.add(b);
        Collections.sort(res);
        return res;
    }
}
