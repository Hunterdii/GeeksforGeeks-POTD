class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            res[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        span[0] = 1;
        for (int i = 1; i < n; i++) {
            span[i] = 1;
            int j = i - 1;
            while (j >= 0 && arr[j] <= arr[i]) {
                span[i] += span[j];
                j -= span[j];
            }
        }
        return span;
    }
};

3)
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        for (int i = 0; i < n; i++) {
            span[i] = 1;
            for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--) 
                span[i]++;
        }
        return span;
    }
};

4)
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n), nge(n, -1);
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && arr[j] <= arr[i]) j = nge[j];
            nge[i] = j;
            span[i] = i - j;
        }
        return span;
    }
};
