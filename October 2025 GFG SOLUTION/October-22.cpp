class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);
        int idx = 0;
        for (int i = k; i < arr.size(); i++) {
            pq.push(arr[i]);
            arr[idx++] = pq.top();
            pq.pop();
        }
        while (!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};

2)
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        for (int i = 1; i < arr.size(); i++) {
            int key = arr[i], j = i - 1;
            while (j >= max(0, i - k - 1) && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};

3)
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i += k + 1) {
            int end = min(i + 2 * k + 1, n);
            sort(arr.begin() + i, arr.begin() + end);
        }
    }
};

4)
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        multiset<int> ms;
        int n = arr.size(), idx = 0;
        for (int i = 0; i <= min(k, n - 1); i++) ms.insert(arr[i]);
        for (int i = k + 1; i < n; i++) {
            arr[idx] = *ms.begin();
            ms.erase(ms.begin());
            ms.insert(arr[i]);
            idx++;
        }
        while (!ms.empty()) {
            arr[idx++] = *ms.begin();
            ms.erase(ms.begin());
        }
    }
};
