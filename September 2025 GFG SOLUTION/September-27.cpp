class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), flips = 0, flip = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && a[i - k] > 1) flip ^= 1;
            if ((a[i] ^ flip) == 0) {
                if (i + k > n) return -1;
                a[i] = 2;
                flip ^= 1;
                flips++;
            }
        }
        return flips;
    }
};

2)
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), flips = 0, current = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            current += diff[i];
            if ((a[i] + current) % 2 == 0) {
                if (i + k > n) return -1;
                diff[i]++;
                diff[i + k]--;
                current++;
                flips++;
            }
        }
        return flips;
    }
};

3)
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), result = 0, active = 0;
        deque<int> flips;
        for (int i = 0; i < n; i++) {
            while (!flips.empty() && flips.front() <= i - k) 
                flips.pop_front();
            int current = a[i] ^ (flips.size() & 1);
            if (current == 0) {
                if (i + k > n) return -1;
                flips.push_back(i);
                result++;
            }
        }
        return result;
    }
};

4)
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && a[i - k] == 2) flipped ^= 1;
            if (a[i] == flipped) {
                if (i + k > n) return -1;
                a[i] = 2;
                flipped ^= 1;
                ans++;
            }
        }
        return ans;
    }
};
