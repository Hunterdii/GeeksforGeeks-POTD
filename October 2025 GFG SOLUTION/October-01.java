class Solution {
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] arr) {
        Arrays.sort(arr);
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        do {
            ArrayList<Integer> perm = new ArrayList<>();
            for (int num : arr) perm.add(num);
            res.add(perm);
        } while (nextPermutation(arr));
        return res;
    }
    private static boolean nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) return false;
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums, i, j);
        reverse(nums, i + 1, n - 1);
        return true;
    }
    private static void swap(int[] nums, int i, int j) {
        int t = nums[i]; nums[i] = nums[j]; nums[j] = t;
    }
    private static void reverse(int[] nums, int i, int j) {
        while (i < j) swap(nums, i++, j--);
    }
}
