class Solution {
    public static ArrayList<Integer> findClosestPair(int arr1[], int arr2[], int x) {
        int i = 0, j = arr2.length - 1, minDiff = Integer.MAX_VALUE;
        ArrayList<Integer> res = new ArrayList<>();
        while (i < arr1.length && j >= 0) {
            int sum = arr1[i] + arr2[j], diff = Math.abs(sum - x);
            if (diff < minDiff) {
                minDiff = diff;
                res = new ArrayList<>(Arrays.asList(arr1[i], arr2[j]));
            }
            if (sum < x) i++;
            else j--;
        }
        return res;
    }
}
