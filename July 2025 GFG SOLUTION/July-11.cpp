class Solution {
public:
    int countConsec(int n) {
        int a = 0, b = 0;
        for (int i = n; i; i--) {
            int tmp = a + b;
            b = a + (1 << (n - i));
            a = tmp;
        }
        return a;
    }
};

2)
class Solution {
public:
    int countConsec(int n) {
        int curr = 0, next = 0;
        for (int i = 0; i < n; i++) {
            int temp = curr + next;
            next = curr + (1 << i);
            curr = temp;
        }
        return curr;
    }
};

3)
class Solution {
public:
    int countConsec(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        int fib1 = 1, fib2 = 2; 
        for (int i = 3; i <= n + 1; i++) {
            int temp = fib1 + fib2;
            fib1 = fib2;
            fib2 = temp;
        }
        return (1 << n) - fib2; 
    }
};

4)
class Solution {
private:
    unordered_map<string, int> memo;
    int countValid(int pos, int lastBit, int n) {
        if (pos == n) return 1;
        string key = to_string(pos) + "_" + to_string(lastBit);
        if (memo.find(key) != memo.end()) return memo[key];
        int result = 0;
        result += countValid(pos + 1, 0, n); 
        if (lastBit != 1) { 
            result += countValid(pos + 1, 1, n);
        }
        return memo[key] = result;
    }
public:
    int countConsec(int n) {
        memo.clear();
        int validStrings = countValid(0, -1, n);
        return (1 << n) - validStrings;
    }
};
