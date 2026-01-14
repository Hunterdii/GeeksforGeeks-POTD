class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), p = 0, t = 0, cnt = 0;
        while (p < n && t < n) {
            while (p < n && arr[p] != 'P') p++;
            while (t < n && arr[t] != 'T') t++;
            if (p < n && t < n && abs(p - t) <= k) {
                cnt++;
                p++;
                t++;
            } else if (t < n && t < p) t++;
            else if (p < n && p < t) p++;
        }
        return cnt;
    }
};

2)
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> p, t;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') p.push_back(i);
            else t.push_back(i);
        }
        int i = 0, j = 0, cnt = 0;
        while (i < p.size() && j < t.size()) {
            if (abs(p[i] - t[j]) <= k) {
                cnt++;
                i++;
                j++;
            } else if (p[i] < t[j]) i++;
            else j++;
        }
        return cnt;
    }
};

3)
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        queue<int> tp, tt;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') tp.push(i);
            else tt.push(i);
        }
        int cnt = 0;
        while (!tp.empty() && !tt.empty()) {
            if (abs(tp.front() - tt.front()) <= k) {
                cnt++;
                tp.pop();
                tt.pop();
            } else if (tp.front() < tt.front()) tp.pop();
            else tt.pop();
        }
        return cnt;
    }
};
