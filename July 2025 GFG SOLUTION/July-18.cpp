class Solution {
public:
    int lcmTriplets(int n) {
        return n < 3 ? n : n & 1 ? n * (n - 1) * (n - 2) : 
              n % 3 ? n * (n - 1) * (n - 3) : (n - 1) * (n - 2) * (n - 3);
    }
};

2)
class Solution {
public:
    int lcmTriplets(int n) {
        if (n < 3) return n;
        int p1 = n - 1, p2 = n - 2, p3 = n - 3;
        return (n & 1) ? n * p1 * p2 : (n % 3) ? n * p1 * p3 : p1 * p2 * p3;
    }
};

3)
class Solution {
public:
    int lcmTriplets(int n) {
        auto f1 = [](int x) { return x; };
        auto f2 = [](int x) { return x * (x - 1) * (x - 2); };
        auto f3 = [](int x) { return x * (x - 1) * (x - 3); };
        auto f4 = [](int x) { return (x - 1) * (x - 2) * (x - 3); };
        return n < 3 ? f1(n) : (n & 1) ? f2(n) : (n % 3) ? f3(n) : f4(n);
    }
};


4)
class Solution {
public:
    int lcmTriplets(int n) {
        if (n < 3) return n;
        if (n % 2 == 1) {
            return n * (n - 1) * (n - 2);
        } else {
            if (n % 3 != 0) {
                return n * (n - 1) * (n - 3);
            } else {
                return (n - 1) * (n - 2) * (n - 3);
            }
        }
    }
};
