class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        priority_queue<tuple<int, int, int>> pq;
        unordered_set<long long> vis;
        pq.emplace(a[0] + b[0], 0, 0);
        vis.insert(0);
        vector<int> res;
        while (res.size() < k) {
            int sum = get<0>(pq.top());
            int i = get<1>(pq.top());
            int j = get<2>(pq.top());
            pq.pop();
            res.push_back(sum);
            if (i + 1 < n && vis.insert((long long)(i + 1) * n + j).second)
                pq.emplace(a[i + 1] + b[j], i + 1, j);
            if (j + 1 < n && vis.insert((long long)i * n + j + 1).second)
                pq.emplace(a[i] + b[j + 1], i, j + 1);
        }
        return res;
    }
};

// Brute-Force Just for Example
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        vector<int> allSums;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                allSums.push_back(a[i] + b[j]);
            }
        }
        sort(allSums.rbegin(), allSums.rend());
        return vector<int>(allSums.begin(), allSums.begin() + k);
    }
};


2)
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<pair<int, pair<int, int>>> pq;
        unordered_set<string> vis;
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert("0,0");
        vector<int> res;
        while (res.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            res.push_back(sum);
            string key1 = to_string(i + 1) + "," + to_string(j);
            string key2 = to_string(i) + "," + to_string(j + 1);
            if (i + 1 < n && vis.find(key1) == vis.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                vis.insert(key1);
            }
            if (j + 1 < n && vis.find(key2) == vis.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                vis.insert(key2);
            }
        }
        return res;
    }
};


3)
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({a[i] + b[0], i});
        }
        vector<int> res;
        vector<int> indices(n, 0);
        while (res.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second;
            res.push_back(sum);
            indices[i]++;
            if (indices[i] < n) {
                pq.push({a[i] + b[indices[i]], i});
            }
        }
        return res;
    }
};


4)
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<pair<int, int>> pq;
        unordered_set<int> vis;
        pq.push({a[0] + b[0], 0});
        vis.insert(0);
        vector<int> res;
        while (res.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int coord = top.second;
            int i = coord / n;
            int j = coord % n;
            res.push_back(sum);
            if (i + 1 < n && vis.find((i + 1) * n + j) == vis.end()) {
                pq.push({a[i + 1] + b[j], (i + 1) * n + j});
                vis.insert((i + 1) * n + j);
            }
            if (j + 1 < n && vis.find(i * n + (j + 1)) == vis.end()) {
                pq.push({a[i] + b[j + 1], i * n + (j + 1)});
                vis.insert(i * n + (j + 1));
            }
        }
        return res;
    }
};
