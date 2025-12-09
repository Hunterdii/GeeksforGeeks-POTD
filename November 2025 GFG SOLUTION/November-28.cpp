class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int r = n & 3;
        int start = (r == 2) ? 2 : 1;
        int end = (r == 3) ? n - 1 : n;
        for (int i = start; i <= end; i++)
            if (r != 1 || i != n - 1) ans.push_back(i);
        return ans;
    }
};

2)
class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int exclude[] = {-1, n - 1, 1, n};
        int mod = n % 4;
        for (int i = 1; i <= n; i++)
            if (i != exclude[mod]) ans.push_back(i);
        return ans;
    }
};

3)
class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int m = n % 4;
        if (m == 0) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 1);
        } else if (m == 2) {
            ans.resize(n - 1);
            iota(ans.begin(), ans.end(), 2);
        } else if (m == 3) {
            ans.resize(n - 1);
            iota(ans.begin(), ans.end(), 1);
        } else {
            for (int i = 1; i <= n; i++)
                if (i != n - 1) ans.push_back(i);
        }
        return ans;
    }
};
