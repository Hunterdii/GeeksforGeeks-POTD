//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < arr.size(); ++i) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(arr[dq.front()]);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        multiset<int> window;
        for (int i = 0; i < arr.size(); ++i) {
            window.insert(arr[i]);
            if (i >= k - 1) {
                res.push_back(*window.rbegin());
                window.erase(window.find(arr[i - k + 1]));
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.emplace(arr[i], i);
            if (i >= k - 1) {
                while (pq.top().second <= i - k) pq.pop();
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
