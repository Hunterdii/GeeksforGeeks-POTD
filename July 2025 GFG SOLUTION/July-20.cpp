class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        int mask = 0, nonZeroMask = 0;
        for (int d : arr) {
            mask |= (1 << d);
            if (d) nonZeroMask |= (1 << d);
        }
        int forbidden = __builtin_popcount(~mask & 1023);
        int nonZeroForbidden = __builtin_popcount(~nonZeroMask & 1022);
        
        int total = 9, pow = 1;
        for (int i = 1; i < n; i++) {
            pow *= 10;
            total *= 10;
        }
        
        int invalid = n == 1 ? nonZeroForbidden : nonZeroForbidden;
        for (int i = 1; i < n; i++) invalid *= forbidden;
        
        return total - invalid;
    }
};

2)
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        bool allowed[10] = {};
        for (int x : arr) allowed[x] = true;
        
        int forbiddenCount = 0, nonZeroForbiddenCount = 0;
        for (int i = 0; i < 10; i++) {
            if (!allowed[i]) {
                forbiddenCount++;
                if (i != 0) nonZeroForbiddenCount++;
            }
        }
        
        int total = 9;
        int power = 1;
        for (int i = 1; i < n; i++) {
            power *= 10;
            total *= 10;
        }
        
        int invalid = (n == 1) ? nonZeroForbiddenCount : nonZeroForbiddenCount;
        for (int i = 1; i < n; i++) invalid *= forbiddenCount;
        
        return total - invalid;
    }
};

3)
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        int goodMask = 0;
        for (int d : arr) goodMask |= (1 << d);
        
        int badDigits = 10 - __builtin_popcount(goodMask);
        int badNonZero = 9 - __builtin_popcount(goodMask & 0x3FE);
        
        long long total = 9;
        long long forbidden = badNonZero;
        
        for (int i = 1; i < n; i++) {
            total *= 10;
            forbidden *= badDigits;
        }
        
        return (int)(total - forbidden);
    }
};

4)
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        bool digit[10] = {};
        for (int x : arr) digit[x] = true;
        
        int f = 0, f0 = 0;
        for (int i = 0; i < 10; i++) {
            if (!digit[i]) {
                f++;
                if (i) f0++;
            }
        }
        
        long long total = 9, invalid = f0, base = 1;
        for (int i = 1; i < n; i++) {
            total *= 10;
            base *= f;
            if (i == n - 1) invalid *= base;
        }
        
        return (int)(total - invalid);
    }
};
