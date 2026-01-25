class Solution {
public:
    int josephus(int n, int k) {
        int pos = 0;
        for (int i = 2; i <= n; i++) pos = (pos + k) % i;
        return pos + 1;
    }
};

2)
class Solution {
public:
    int josephus(int n, int k) {
        return n == 1 ? 1 : (josephus(n - 1, k) + k - 1) % n + 1;
    }
};

3)
class Solution {
public:
    int josephus(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; i++) res = (res + k) % i;
        return res + 1;
    }
};

4)
class Solution {
public:
    int josephus(int n, int k) {
        if (k == 2) {
            int p = 1;
            while (p * 2 <= n) p *= 2;
            return 2 * (n - p) + 1;
        }
        int pos = 0;
        for (int i = 2; i <= n; i++) pos = (pos + k) % i;
        return pos + 1;
    }
};
