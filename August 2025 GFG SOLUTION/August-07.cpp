class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<int> mins;
        for (auto& t : arr) {
            int h = (t[0] - '0') * 10 + (t[1] - '0');
            int m = (t[3] - '0') * 10 + (t[4] - '0');
            int s = (t[6] - '0') * 10 + (t[7] - '0');
            mins.push_back(h * 3600 + m * 60 + s);
        }
        sort(mins.begin(), mins.end());
        int res = mins[0] + 86400 - mins.back();
        for (int i = 1; i < mins.size(); i++) {
            res = min(res, mins[i] - mins[i-1]);
        }
        return res;
    }
};

2)
class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<bool> seen(86400, false);
        for (auto& t : arr) {
            int sec = ((t[0]-'0')*10+(t[1]-'0'))*3600 + ((t[3]-'0')*10+(t[4]-'0'))*60 + (t[6]-'0')*10+(t[7]-'0');
            if (seen[sec]) return 0;
            seen[sec] = true;
        }
        int prev = -1, first = -1, res = 86400;
        for (int i = 0; i < 86400; i++) {
            if (!seen[i]) continue;
            if (prev == -1) first = i;
            else res = min(res, i - prev);
            prev = i;
        }
        return min(res, first + 86400 - prev);
    }
};

3)
class Solution {
public:
    int minDifference(vector<string>& arr) {
        set<int> times;
        for (auto& t : arr) {
            int sec = stoi(t.substr(0,2))*3600 + stoi(t.substr(3,2))*60 + stoi(t.substr(6,2));
            if (!times.insert(sec).second) return 0;
        }
        vector<int> sorted(times.begin(), times.end());
        int res = sorted[0] + 86400 - sorted.back();
        for (int i = 1; i < sorted.size(); i++) {
            res = min(res, sorted[i] - sorted[i-1]);
        }
        return res;
    }
};

4)
class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<int> secs;
        for (auto& t : arr) {
            secs.push_back(((t[0]-'0')*10+(t[1]-'0'))*3600 + 
                          ((t[3]-'0')*10+(t[4]-'0'))*60 + 
                          (t[6]-'0')*10+(t[7]-'0'));
        }
        sort(secs.begin(), secs.end());
        int res = secs[0] + 86400 - secs.back();
        for (int i = 1; i < secs.size(); i++) {
            if (secs[i] == secs[i-1]) return 0;
            res = min(res, secs[i] - secs[i-1]);
        }
        return res;
    }
};
