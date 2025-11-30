class Solution {
    public static ArrayList<Integer> subsetXOR(int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        int r = n & 3;
        int start = (r == 2) ? 2 : 1;
        int end = (r == 3) ? n - 1 : n;
        for (int i = start; i <= end; i++)
            if (r != 1 || i != n - 1) ans.add(i);
        return ans;
    }
}
