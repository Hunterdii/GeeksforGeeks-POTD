class Solution {
    public int maxOnes(int arr[], int k) {
        int l = 0, zeros = 0, maxLen = 0;
        for (int r = 0; r < arr.length; r++) {
            if (arr[r] == 0) zeros++;
            while (zeros > k) if (arr[l++] == 0) zeros--;
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}
