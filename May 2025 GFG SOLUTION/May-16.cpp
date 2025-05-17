//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size(), l = 0, r = n - 1, i = A >= 0 ? n - 1 : 0;
        vector<int> res(n);
        auto f = [&](int x) { return A * x * x + B * x + C; };
        while (l <= r) {
            int lv = f(arr[l]), rv = f(arr[r]);
            if (A >= 0) res[i--] = lv > rv ? lv : rv, lv > rv ? ++l : --r;
            else res[i++] = lv < rv ? lv : rv, lv < rv ? ++l : --r;
        }
        return res;
    }
};


2)
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = A*arr[i]*arr[i] + B*arr[i] + C;
        sort(res.begin(), res.end());
        return res;
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
