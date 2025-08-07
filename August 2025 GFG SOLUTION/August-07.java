class Solution {
    public int minDifference(String[] arr) {
        int[] mins = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            String t = arr[i];
            int h = (t.charAt(0) - '0') * 10 + (t.charAt(1) - '0');
            int m = (t.charAt(3) - '0') * 10 + (t.charAt(4) - '0');
            int s = (t.charAt(6) - '0') * 10 + (t.charAt(7) - '0');
            mins[i] = h * 3600 + m * 60 + s;
        }
        Arrays.sort(mins);
        int res = mins[0] + 86400 - mins[mins.length - 1];
        for (int i = 1; i < mins.length; i++) {
            res = Math.min(res, mins[i] - mins[i - 1]);
        }
        return res;
    }
}
