class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size(), need = (n + 1) / 2, total = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : arr) pq.push(x % k ? k - x % k : 0);
        while (need--) total += pq.top(), pq.pop();
        return total;
    }
};

2)
class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        vector<int> costs;
        int need = (arr.size() + 1) / 2;
        for (int x : arr) costs.push_back(x % k ? k - x % k : 0);
        nth_element(costs.begin(), costs.begin() + need - 1, costs.end());
        return accumulate(costs.begin(), costs.begin() + need, 0);
    }
};

3)
class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size(), need = (n + 1) / 2;
        for (int& x : arr) x = x % k ? k - x % k : 0;
        partial_sort(arr.begin(), arr.begin() + need, arr.end());
        return accumulate(arr.begin(), arr.begin() + need, 0);
    }
};
