class Solution {
    int[] smallestDiff(int a[], int b[], int c[]) {
        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);
        int i = 0, j = 0, k = 0, diff = Integer.MAX_VALUE;
        int[] res = new int[3];
        while (i < a.length && j < b.length && k < c.length) {
            int minVal = Math.min(a[i], Math.min(b[j], c[k]));
            int maxVal = Math.max(a[i], Math.max(b[j], c[k]));
            int midVal = a[i] + b[j] + c[k] - minVal - maxVal;
            if (maxVal - minVal < diff) {
                diff = maxVal - minVal;
                res[0] = maxVal;
                res[1] = midVal;
                res[2] = minVal;
            }
            if (minVal == a[i]) i++;
            else if (minVal == b[j]) j++;
            else k++;
        }
        return res;
    }
}
