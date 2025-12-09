class Solution {
    int subsetXORSum(int arr[]) {
        int orVal = 0;
        for (int x : arr) orVal |= x;
        return orVal << (arr.length - 1);
    }
}
