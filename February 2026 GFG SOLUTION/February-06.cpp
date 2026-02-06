class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0, diff = INT_MAX;
        vector<int> res(3);
        while (i < a.size() && j < b.size() && k < c.size()) {
            int minVal = min({a[i], b[j], c[k]});
            int maxVal = max({a[i], b[j], c[k]});
            int midVal = a[i] + b[j] + c[k] - minVal - maxVal;
            if (maxVal - minVal < diff) {
                diff = maxVal - minVal;
                res = {maxVal, midVal, minVal};
            }
            if (minVal == a[i]) i++;
            else if (minVal == b[j]) j++;
            else k++;
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0, minDiff = INT_MAX, minSum = INT_MAX;
        vector<int> res(3);
        while (i < a.size() && j < b.size() && k < c.size()) {
            int minVal = min({a[i], b[j], c[k]});
            int maxVal = max({a[i], b[j], c[k]});
            int midVal = a[i] + b[j] + c[k] - minVal - maxVal;
            int currDiff = maxVal - minVal;
            int currSum = a[i] + b[j] + c[k];
            if (currDiff < minDiff || (currDiff == minDiff && currSum < minSum)) {
                minDiff = currDiff;
                minSum = currSum;
                res = {maxVal, midVal, minVal};
            }
            if (minVal == a[i]) i++;
            else if (minVal == b[j]) j++;
            else k++;
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int p = 0, q = 0, r = 0, best = INT_MAX;
        int resMax, resMid, resMin;
        while (p < a.size() && q < b.size() && r < c.size()) {
            int lo = min({a[p], b[q], c[r]});
            int hi = max({a[p], b[q], c[r]});
            int mid = a[p] + b[q] + c[r] - lo - hi;
            if (hi - lo < best) {
                best = hi - lo;
                resMax = hi;
                resMid = mid;
                resMin = lo;
            }
            if (a[p] == lo) p++;
            else if (b[q] == lo) q++;
            else r++;
        }
        return {resMax, resMid, resMin};
    }
};

4)
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0, d = INT_MAX;
        int x, y, z;
        while (i < a.size() && j < b.size() && k < c.size()) {
            int mn = min({a[i], b[j], c[k]});
            int mx = max({a[i], b[j], c[k]});
            if (mx - mn < d) {
                d = mx - mn;
                x = mx;
                y = a[i] + b[j] + c[k] - mx - mn;
                z = mn;
            }
            if (a[i] == mn) i++;
            else if (b[j] == mn) j++;
            else k++;
        }
        return {x, y, z};
    }
};
