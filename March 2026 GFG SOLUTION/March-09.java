class Solution {
    public String largestSwap(String s) {
        char[] a = s.toCharArray();
        int[] last = new int[10];
        java.util.Arrays.fill(last, -1);
        for (int i = 0; i < a.length; i++) last[a[i] - '0'] = i;
        for (int i = 0; i < a.length; i++)
            for (int d = 9; d > a[i] - '0'; d--)
                if (last[d] > i) { char t = a[i]; a[i] = a[last[d]]; a[last[d]] = t; return new String(a); }
        return s;
    }
}
