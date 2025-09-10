class Solution {
    public String largestSwap(String s) {
        char[] a = s.toCharArray();
        int n = a.length, l = -1, r = -1, maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[maxIdx]) maxIdx = i;
            else if (a[i] < a[maxIdx]) { l = i; r = maxIdx; }
        }
        if (l != -1) { char t = a[l]; a[l] = a[r]; a[r] = t; }
        return new String(a);
    }
}
