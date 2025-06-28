
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(), mx = *max_element(b.begin(), b.end());
        vector<int> res(n), cnt(mx + 1);
        for (int x : b) cnt[x]++;
        for (int i = 1; i <= mx; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) res[i] = cnt[min(a[i], mx)];
        return res;
    }
};


2)
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        vector<int> res;
        for (int x : a)
            res.push_back(upper_bound(b.begin(), b.end(), x) - b.begin());
        return res;
    }
};


3)
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> res(a.size());
        map<int, int> freq;
        for (int x : b) freq[x]++;
        
        vector<pair<int, int>> sorted_freq;
        for (auto& p : freq) sorted_freq.push_back(p);
        
        for (int i = 1; i < sorted_freq.size(); i++) {
            sorted_freq[i].second += sorted_freq[i-1].second;
        }
        
        for (int i = 0; i < a.size(); i++) {
            auto it = upper_bound(sorted_freq.begin(), sorted_freq.end(), 
                                make_pair(a[i], INT_MAX));
            res[i] = (it == sorted_freq.begin()) ? 0 : prev(it)->second;
        }
        return res;
    }
};
