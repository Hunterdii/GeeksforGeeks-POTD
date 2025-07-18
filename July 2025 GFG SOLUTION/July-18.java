class Solution {
    int lcmTriplets(int n) {
        return n < 3 ? n : (n & 1) == 1 ? n * (n - 1) * (n - 2) : 
               n % 3 != 0 ? n * (n - 1) * (n - 3) : (n - 1) * (n - 2) * (n - 3);
    }
}
