class Solution {
    public ArrayList<Integer> missingRange(int[] arr, int low, int high) {
        boolean[] present = new boolean[high - low + 1];
        for (int x : arr) {
            if (x >= low && x <= high) present[x - low] = true;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i <= high - low; i++) {
            if (!present[i]) ans.add(low + i);
        }
        return ans;
    }
}
