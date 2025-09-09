class Solution {
public:
    int assignHole(vector<int>& m, vector<int>& h) {
        sort(m.begin(), m.end());
        sort(h.begin(), h.end());
        int r = 0;
        for (int i = 0; i < m.size(); ++i) 
            r = max(r, abs(m[i] - h[i]));
        return r;
    }
};


2)
class Solution {
public:
    int assignHole(vector<int>& mice, vector<int>& holes) {
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());
        vector<int> diff(mice.size());
        transform(mice.begin(), mice.end(), holes.begin(), diff.begin(),
                 [](int m, int h) { return abs(m - h); });
        return *max_element(diff.begin(), diff.end());
    }
};


3)
class Solution {
public:
    int assignHole(vector<int>& mice, vector<int>& holes) {
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());
        int maxTime = 0;
        auto m = mice.begin(), h = holes.begin();
        while (m != mice.end()) {
            maxTime = max(maxTime, abs(*m++ - *h++));
        }
        return maxTime;
    }
};
