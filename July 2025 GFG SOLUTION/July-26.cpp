class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size(), a = 0, b = 1, ca = 0, cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
            else if (!ca) a = x, ca = 1;
            else if (!cb) b = x, cb = 1;
            else ca--, cb--;
        }
        ca = cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
        }
        vector<int> res;
        if (ca > n / 3) res.push_back(a);
        if (cb > n / 3 && a != b) res.push_back(b);
        sort(res.begin(), res.end());
        return res;
    }
};

2)
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res;
        for (auto& p : freq) {
            if (p.second > n / 3) res.push_back(p.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

3)
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> res;
        for (int i = 0; i < n; ) {
            int cnt = 1, val = arr[i];
            while (++i < n && arr[i] == val) cnt++;
            if (cnt > n / 3) res.push_back(val);
        }
        return res;
    }
};

4)
class Solution {
private:
    vector<int> merge(vector<int>& arr, vector<int> left, vector<int> right, int l, int r) {
        vector<int> candidates;
        for (int x : left) candidates.push_back(x);
        for (int x : right) candidates.push_back(x);
        
        vector<int> res;
        for (int cand : candidates) {
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if (arr[i] == cand) cnt++;
            }
            if (cnt > (r - l + 1) / 3) {
                if (find(res.begin(), res.end(), cand) == res.end()) {
                    res.push_back(cand);
                }
            }
        }
        return res;
    }
    
    vector<int> majorityRec(vector<int>& arr, int l, int r) {
        if (l == r) return {arr[l]};
        int mid = l + (r - l) / 2;
        vector<int> left = majorityRec(arr, l, mid);
        vector<int> right = majorityRec(arr, mid + 1, r);
        return merge(arr, left, right, l, r);
    }
    
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = majorityRec(arr, 0, n - 1);
        vector<int> res;
        for (int cand : candidates) {
            int cnt = 0;
            for (int x : arr) {
                if (x == cand) cnt++;
            }
            if (cnt > n / 3) res.push_back(cand);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
