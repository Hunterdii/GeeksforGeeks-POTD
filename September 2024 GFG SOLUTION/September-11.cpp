//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());
        long long totalCost = 0;
        while (minHeap.size() > 1) {
            long long first = minHeap.top(); minHeap.pop();
            long long second = minHeap.top(); minHeap.pop();
            long long cost = first + second;
            totalCost += cost;
            minHeap.push(cost);
        }
        return totalCost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends
