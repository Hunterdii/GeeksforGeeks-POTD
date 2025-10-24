class Solution {
public:
    bool isPossible(vector<int>& a, int k) {
        unordered_map<int,int> freq, need;
        for (int x : a) freq[x]++;
        for (int x : a) {
            if (!freq[x]) continue;
            freq[x]--;
            if (need[x] > 0) need[x]--, need[x + 1]++;
            else {
                for (int i = 1; i < k; i++) {
                    if (--freq[x + i] < 0) return false;
                }
                need[x + k]++;
            }
        }
        return true;
    }
};

2)
class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int x : arr) {
            if (m[x - 1].size()) {
                int len = m[x - 1].top();
                m[x - 1].pop();
                m[x].push(len + 1);
            } else {
                m[x].push(1);
            }
        }
        for (auto& p : m) {
            while (p.second.size()) {
                if (p.second.top() < k) return false;
                p.second.pop();
            }
        }
        return true;
    }
};

3)
class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        map<int, int> cnt, end;
        for (int x : arr) cnt[x]++;
        for (int x : arr) {
            if (!cnt[x]) continue;
            cnt[x]--;
            if (end[x - 1]) {
                end[x - 1]--;
                end[x]++;
            } else {
                bool ok = true;
                for (int i = 1; i < k; i++) {
                    if (cnt[x + i] <= 0) {ok = false; break;}
                    cnt[x + i]--;
                }
                if (!ok) return false;
                end[x + k - 1]++;
            }
        }
        return true;
    }
};
