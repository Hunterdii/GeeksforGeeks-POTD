class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<pair<int, int>> v;
        for (auto& p : freq) v.push_back({p.second, p.first});
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<pair<int, int>>());
        sort(v.begin(), v.begin() + k, greater<pair<int, int>>());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

3)
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<pair<int, int>> v;
        for (auto& p : freq) v.push_back({p.second, p.first});
        sort(v.rbegin(), v.rend());
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(v[i].second);
        return res;
    }
};

4)
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int x : arr) maxFreq = max(maxFreq, ++freq[x]);
        vector<vector<int>> buckets(maxFreq + 1);
        for (auto& [num, f] : freq) buckets[f].push_back(num);
        vector<int> res;
        for (int i = maxFreq; i > 0 && res.size() < k; i--) {
            sort(buckets[i].rbegin(), buckets[i].rend());
            for (int x : buckets[i]) {
                res.push_back(x);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
