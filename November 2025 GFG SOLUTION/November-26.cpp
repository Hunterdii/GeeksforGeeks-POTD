class Solution {
public:
    int andInRange(int l, int r) {
        while (l < r) r &= r - 1;
        return r;
    }
};

2)
class Solution {
public:
    int andInRange(int l, int r) {
        int shift = 0;
        while (l != r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        return l << shift;
    }
};

3)
class Solution {
public:
    int andInRange(int l, int r) {
        int xor_val = l ^ r;
        int msb = 0;
        while (xor_val) {
            xor_val >>= 1;
            msb++;
        }
        int mask = (~0) << msb;
        return l & mask;
    }
};

4)
class Solution {
public:
    int andInRange(int l, int r) {
        while (l < r) r -= r & -r;
        return r;
    }
};

5)
class Solution {
public:
    int andInRange(int l, int r) {
        int shift = 0;
        while ((l >> shift) != (r >> shift)) shift++;
        return (l >> shift) << shift;
    }
};
