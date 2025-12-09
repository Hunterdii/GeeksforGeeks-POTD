class Solution {
    public int subarrayXor(int[] arr) {
        int xor_sum = 0;
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if ((((i + 1) * (n - i)) & 1) == 1) xor_sum ^= arr[i];
        }
        return xor_sum;
    }
}
