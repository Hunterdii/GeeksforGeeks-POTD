//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
1)
class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        int n = arr.size();
        long long res = 1;
        for (int i = 0; i < n && arr[i] <= res; i++)
            res = res + arr[i];

        return res;
    }
};

2)
class Solution {
  public:
    long long findSmallest(std::vector<int> &arr) {
        std::sort(arr.begin(), arr.end());
        long long res = 1;
        for (int i = 0; i < arr.size() && arr[i] <= res; i++)
            res += arr[i];

        return res;
    }
};

3)
class Solution {
  public:
    long long findSmallest(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end()); 
        long long res = 1; 
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > res) {
                break;
            }
            res += arr[i]; 
        }

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
