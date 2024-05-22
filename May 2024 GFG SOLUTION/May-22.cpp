//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int countIntervals(double x, const vector<int>& v) {
        int ret = 0;
        for (size_t i = 0; i < v.size() - 1; ++i)
            ret += static_cast<int>(ceil((v[i + 1] - v[i]) / x)) - 1;
        return ret;
    }

public:
    double findSmallestMaxDist(vector<int>& s, int k) {
        sort(s.begin(), s.end());
        int n = s.size();
        double l = 1e-9; // Start with a very small positive value to avoid division by zero
        double h = s[n - 1] - s[0];
        
        while ((h - l) > 1e-6) {
            double mid = l + (h - l) / 2.0;
            int intervals = countIntervals(mid, s);
            if (intervals > k)
                l = mid;
            else
                h = mid;
        }
        return h;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends
