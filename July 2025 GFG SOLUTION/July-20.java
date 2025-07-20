class Solution {
    public int countValid(int n, int[] arr) {
        boolean[] allowed = new boolean[10];
        for (int d : arr) allowed[d] = true;
        
        int forbidden = 0, nonZeroForbidden = 0;
        for (int i = 0; i < 10; i++) {
            if (!allowed[i]) {
                forbidden++;
                if (i != 0) nonZeroForbidden++;
            }
        }
        
        long total = 9;
        for (int i = 1; i < n; i++) total *= 10;
        
        long invalid = (n == 1) ? nonZeroForbidden : nonZeroForbidden;
        for (int i = 1; i < n; i++) invalid *= forbidden;
        
        return (int)(total - invalid);
    }
}
