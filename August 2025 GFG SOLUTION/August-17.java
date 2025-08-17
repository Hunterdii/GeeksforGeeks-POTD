class Solution {
    public void rearrange(int[] arr, int x) {
        Integer[] indices = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> Integer.compare(Math.abs(arr[a] - x), Math.abs(arr[b] - x)));
        int[] temp = new int[arr.length];
        for (int i = 0; i < arr.length; i++) temp[i] = arr[indices[i]];
        System.arraycopy(temp, 0, arr, 0, arr.length);
    }
}
