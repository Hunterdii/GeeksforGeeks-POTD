//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> constructLowerArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(n + 1, 0);
        vector<int> ans(n, 0);

        auto update = [&](int index, int value) {
            for (; index <= n; index += index & (-index)) {
                bit[index] += value;
            }
        };

        auto get = [&](int index) {
            int sum = 0;
            for (; index > 0; index -= index & (-index)) {
                sum += bit[index];
            }
            return sum;
        };

        vector<pair<int, int>> value_index_pairs;
        for (int i = 0; i < n; ++i) {
            value_index_pairs.push_back({nums[i], i});
        }

        sort(value_index_pairs.begin(), value_index_pairs.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < n; ++i) {
            rank[value_index_pairs[i].first] = i + 1;
        }

        for (int i = n - 1; i >= 0; --i) {
            int index = rank[nums[i]];
            ans[i] = get(index - 1);
            update(index, 1);
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
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
