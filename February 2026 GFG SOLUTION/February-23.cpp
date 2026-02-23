class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        vector<int> res(a.begin(), a.end());
        res.insert(res.end(), b.begin(), b.end());
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

2)
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;
        for (int x : a) st.insert(x);
        for (int x : b) st.insert(x);
        return vector<int>(st.begin(), st.end());
    }
};

3)
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        for (int x : a) s.insert(x);
        for (int x : b) s.insert(x);
        return vector<int>(s.begin(), s.end());
    }
};

4)
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int, bool> mp;
        vector<int> res;
        for (int x : a) mp[x] = true;
        for (int x : b) mp[x] = true;
        for (auto& p : mp) res.push_back(p.first);
        return res;
    }
};

5)
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                if (res.empty() || res.back() != b[j]) res.push_back(b[j]);
                j++;
            } else {
                if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
                i++; j++;
            }
        }
        while (i < a.size()) {
            if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
            i++;
        }
        while (j < b.size()) {
            if (res.empty() || res.back() != b[j]) res.push_back(b[j]);
            j++;
        }
        return res;
    }
};
