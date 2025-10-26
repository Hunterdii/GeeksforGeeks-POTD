class Solution {
public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int res = 0;
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        return res;
    }
};

2)
class Solution {
public:
    int minCost(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        queue<int> q1, q2;
        for (int x : arr) q1.push(x);
        int res = 0;
        while (q1.size() + q2.size() > 1) {
            int first = INT_MAX, second = INT_MAX;
            if (!q1.empty() && (q2.empty() || q1.front() <= q2.front())) {
                first = q1.front(); q1.pop();
            } else {
                first = q2.front(); q2.pop();
            }
            if (!q1.empty() && (q2.empty() || q1.front() <= q2.front())) {
                second = q1.front(); q1.pop();
            } else {
                second = q2.front(); q2.pop();
            }
            int sum = first + second;
            res += sum;
            q2.push(sum);
        }
        return res;
    }
};

3)
class Solution {
public:
    int minCost(vector<int>& arr) {
        multiset<int> ms(arr.begin(), arr.end());
        int res = 0;
        while (ms.size() > 1) {
            auto it = ms.begin();
            int first = *it;
            ms.erase(it);
            it = ms.begin();
            int second = *it;
            ms.erase(it);
            res += first + second;
            ms.insert(first + second);
        }
        return res;
    }
};

4)
class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }
    
    int minCost(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
        int res = 0, size = n;
        while (size > 1) {
            int first = arr[0];
            arr[0] = arr[--size];
            heapify(arr, size, 0);
            int second = arr[0];
            arr[0] = arr[--size];
            heapify(arr, size, 0);
            int sum = first + second;
            res += sum;
            arr[size++] = sum;
            heapify(arr, size, 0);
        }
        return res;
    }
};
