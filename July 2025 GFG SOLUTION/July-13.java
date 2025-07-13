class Solution {
    public int nonLisMaxSum(int[] arr) {
        ArrayList<Integer> dp = new ArrayList<>();
        ArrayList<Integer> sums = new ArrayList<>();
        int total = Arrays.stream(arr).sum();
        for (int x : arr) {
            int idx = Collections.binarySearch(dp, x);
            if (idx < 0) idx = -idx - 1;
            if (idx == dp.size()) {
                dp.add(x);
                sums.add((sums.isEmpty() ? 0 : sums.get(sums.size() - 1)) + x);
            } else {
                dp.set(idx, x);
                sums.set(idx, (idx > 0 ? sums.get(idx - 1) : 0) + x);
            }
        }
        return total - sums.get(sums.size() - 1);
    }
}
