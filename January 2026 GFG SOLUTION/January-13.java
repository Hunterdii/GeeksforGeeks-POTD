class Solution {
    public boolean canServe(int[] arr) {
        int f = 0, t = 0;
        for (int x : arr) {
            if (x == 5) f++;
            else if (x == 10) {
                if (f == 0) return false;
                f--; t++;
            } else {
                if (t > 0 && f > 0) { t--; f--; }
                else if (f >= 3) f -= 3;
                else return false;
            }
        }
        return true;
    }
}
