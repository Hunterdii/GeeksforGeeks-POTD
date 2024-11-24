//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int getMinDiff(int k, vector<int>& arr) {
        vector<pair<int, int>> v;
        int n = arr.size();
        vector<int> taken(n, 0); 

        for (int i = 0; i < n; i++) {
            v.emplace_back(arr[i] - k, i);
            v.emplace_back(arr[i] + k, i);
        }

        sort(v.begin(), v.end());

        int elements_in_range = 0, left = 0, ans = INT_MAX;

        for (int right = 0; right < v.size(); right++) {
            if (taken[v[right].second]++ == 0) {
                elements_in_range++;
            }

            while (elements_in_range == n) {
                ans = min(ans, v[right].first - v[left].first);

                if (--taken[v[left].second] == 0) {
                    elements_in_range--;
                }
                left++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
