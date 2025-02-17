//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);
        for (int i = k; i < arr.size(); i++) 
            if (arr[i] > pq.top()) pq.pop(), pq.push(arr[i]);
        vector<int> res(k);
        while (!pq.empty()) res[--k] = pq.top(), pq.pop();
        return res;
    }
};

2)
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        nth_element(arr.begin(), arr.end() - k, arr.end());
        partial_sort(arr.end() - k, arr.end(), arr.end(), greater<int>());
        return vector<int>(arr.end() - k, arr.end());
    }
};


3)
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        sort(arr.rbegin(), arr.rend());
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

4)
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);
        for (int i = k; i < arr.size(); i++)
            if (arr[i] > pq.top()) pq.pop(), pq.push(arr[i]);
        vector<int> res(k);
        while (!pq.empty()) res[--k] = pq.top(), pq.pop();
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
