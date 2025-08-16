class Solution {
    public String findLargest(int[] arr) {
        String[] s = new String[arr.length];
        for (int i = 0; i < arr.length; i++) s[i] = String.valueOf(arr[i]);
        Arrays.sort(s, (x, y) -> (x + y).compareTo(y + x) > 0 ? -1 : 1); 
        if (s[0].equals("0")) return "0";
        StringBuilder res = new StringBuilder();
        Arrays.stream(s).forEach(res::append);
        return res.toString();
    }
}
