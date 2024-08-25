//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long countPairs(vector<int>& arr, vector<int>& brr) {
        int N = brr.size();
        vector<int> NoOfY(5, 0);
        for (int i = 0; i < N; i++) {
            if (brr[i] < 5) NoOfY[brr[i]]++;
        }
        sort(brr.begin(), brr.end());
        long long total_pairs = 0;
        for (int x : arr) {
            if (x == 0) continue;
            if (x == 1) {
                total_pairs += NoOfY[0];
                continue;
            }
            int idx = upper_bound(brr.begin(), brr.end(), x) - brr.begin();
            long long count = N - idx;

            count += (NoOfY[0] + NoOfY[1]);
            if (x == 2) count -= (NoOfY[3] + NoOfY[4]);
            if (x == 3) count += NoOfY[2];

            total_pairs += count;
        }

        return total_pairs;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
