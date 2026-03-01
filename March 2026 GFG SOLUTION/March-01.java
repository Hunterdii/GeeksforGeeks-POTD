class Solution {
    void pushZerosToEnd(int[] arr) {
        int pos = 0;
        for (int i = 0; i < arr.length; i++)
            if (arr[i] != 0) arr[pos++] = arr[i];
        while (pos < arr.length) arr[pos++] = 0;
    }
}
