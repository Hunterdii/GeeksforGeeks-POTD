class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        for(int i = 0; i < min((int)arr1.size(), k); i++) pq.push({arr1[i] + arr2[0], {i, 0}});
        while(k-- && !pq.empty()) {
            auto [sum, idx] = pq.top(); pq.pop();
            auto [i, j] = idx;
            res.push_back({arr1[i], arr2[j]});
            if(j + 1 < arr2.size()) pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
        }
        return res;
    }
};.

2)
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        set<pair<int,int>> vis;
        pq.push({arr1[0] + arr2[0], 0, 0});
        vis.insert({0, 0});
        while(k-- && !pq.empty()) {
            auto v = pq.top(); pq.pop();
            int i = v[1], j = v[2];
            res.push_back({arr1[i], arr2[j]});
            if(i + 1 < arr1.size() && !vis.count({i+1, j})) {
                pq.push({arr1[i+1] + arr2[j], i+1, j});
                vis.insert({i+1, j});
            }
            if(j + 1 < arr2.size() && !vis.count({i, j+1})) {
                pq.push({arr1[i] + arr2[j+1], i, j+1});
                vis.insert({i, j+1});
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        auto cmp = [&](pair<int,int> a, pair<int,int> b) {
            return arr1[a.first] + arr2[a.second] > arr1[b.first] + arr2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < min((int)arr1.size(), k); i++) pq.push({i, 0});
        while(k-- && !pq.empty()) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({arr1[i], arr2[j]});
            if(j + 1 < arr2.size()) pq.push({i, j + 1});
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<pair<int, pair<int,int>>> pairs;
        for(int i = 0; i < arr1.size(); i++)
            for(int j = 0; j < arr2.size(); j++)
                pairs.push_back({arr1[i] + arr2[j], {arr1[i], arr2[j]}});
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> res;
        for(int i = 0; i < k && i < pairs.size(); i++)
            res.push_back({pairs[i].second.first, pairs[i].second.second});
        return res;
    }
};
