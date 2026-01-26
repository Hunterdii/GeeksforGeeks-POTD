class Solution {
    public static ArrayList<ArrayList<Integer>> permuteDist(int[] arr) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        Arrays.sort(arr);
        res.add(toList(arr));
        while (nextPerm(arr)) res.add(toList(arr));
        return res;
    }
    static boolean nextPerm(int[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i < 0) return false;
        int j = arr.length - 1;
        while (arr[j] <= arr[i]) j--;
        swap(arr, i, j);
        reverse(arr, i + 1);
        return true;
    }
    static void swap(int[] arr, int i, int j) {
        int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
    }
    static void reverse(int[] arr, int start) {
        int i = start, j = arr.length - 1;
        while (i < j) swap(arr, i++, j--);
    }
    static ArrayList<Integer> toList(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int x : arr) list.add(x);
        return list;
    }
}
