class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = accumulate(arr.begin(), arr.end(), 0.0), t = s / 2;
        priority_queue<double> q(arr.begin(), arr.end());
        int ops = 0;
        while (s > t) {
            double x = q.top(); q.pop();
            s -= x / 2;
            q.push(x / 2);
            ops++;
        }
        return ops;
    }
};

2)
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = 0, t;
        vector<double> h;
        for (int x : arr) {
            s += x;
            h.push_back(x);
        }
        t = s / 2;
        make_heap(h.begin(), h.end());
        int ops = 0;
        while (s > t) {
            pop_heap(h.begin(), h.end());
            double x = h.back();
            h.pop_back();
            x /= 2;
            s -= x;
            h.push_back(x);
            push_heap(h.begin(), h.end());
            ops++;
        }
        return ops;
    }
};

3)
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = 0;
        multiset<double> ms;
        for (int x : arr) {
            s += x;
            ms.insert(x);
        }
        double t = s / 2;
        int ops = 0;
        while (s > t) {
            auto it = prev(ms.end());
            double x = *it;
            ms.erase(it);
            x /= 2;
            s -= x;
            ms.insert(x);
            ops++;
        }
        return ops;
    }
};

4)
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = 0;
        vector<double> v;
        for (int x : arr) {
            s += x;
            v.push_back(x);
        }
        double t = s / 2;
        sort(v.rbegin(), v.rend());
        int ops = 0;
        while (s > t) {
            double x = v[0];
            v.erase(v.begin());
            x /= 2;
            s -= x;
            v.insert(lower_bound(v.begin(), v.end(), x, greater<double>()), x);
            ops++;
        }
        return ops;
    }
};
