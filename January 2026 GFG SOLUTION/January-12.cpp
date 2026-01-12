class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < arr.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(arr[dq.front()]);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        multiset<int> ms;
        for (int i = 0; i < k; i++) ms.insert(arr[i]);
        res.push_back(*ms.rbegin());
        for (int i = k; i < arr.size(); i++) {
            ms.erase(ms.find(arr[i - k]));
            ms.insert(arr[i]);
            res.push_back(*ms.rbegin());
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        for (int i = 0; i <= arr.size() - k; i++) {
            int mx = arr[i];
            for (int j = i + 1; j < i + k; j++) mx = max(mx, arr[j]);
            res.push_back(mx);
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> left(n), right(n), res;
        for (int i = 0; i < n; i++) {
            if (i % k == 0) left[i] = arr[i];
            else left[i] = max(left[i - 1], arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || (i + 1) % k == 0) right[i] = arr[i];
            else right[i] = max(right[i + 1], arr[i]);
        }
        for (int i = 0; i <= n - k; i++) res.push_back(max(right[i], left[i + k - 1]));
        return res;
    }
};
