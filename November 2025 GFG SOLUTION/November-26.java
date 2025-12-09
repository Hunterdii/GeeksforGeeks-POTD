class Solution {
    public int andInRange(int l, int r) {
        while (l < r) r &= r - 1;
        return r;
    }
}
