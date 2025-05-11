//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++



class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int> p(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) p[i + 1] = p[i] + arr[i];
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j <= arr.size(); ++j) {
                q.push(p[j] - p[i]);
                if (q.size() > k) q.pop();
            }
        return q.top();
    }
};

2)
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> sums;
        sums.reserve(n*(n+1)/2);
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                sums.push_back(accumulate(arr.begin()+i, arr.begin()+j+1, 0));
        sort(sums.begin(), sums.end(), greater<int>());
        return sums[k-1];
    }
};

3)
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> P(n+1,0);
        for(int i=1;i<=n;++i) P[i]=P[i-1]+arr[i-1];
        priority_queue<int> maxHeap;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<=n;++j)
                maxHeap.push(P[j]-P[i]);
        while(--k) maxHeap.pop();
        return maxHeap.top();
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
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
