//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
1)
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxProduct = arr[0], maxVal = arr[0], minVal = arr[0];

        for (int i = 1; i < n; ++i) {
            int current = arr[i];

            if (current < 0) swap(maxVal, minVal);

            maxVal = max(current, maxVal * current);
            minVal = min(current, minVal * current);

            maxProduct = max(maxProduct, maxVal);
        }

        return maxProduct;
    }
};

2)
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxProduct = arr[0], maxVal = arr[0], minVal = arr[0];

        for (int i = 1; i < n; ++i) {
            int current = arr[i];

            if (current < 0) {
                int temp = maxVal;
                maxVal = minVal;
                minVal = temp;
            }

            maxVal = (current > maxVal * current) ? current : maxVal * current;
            minVal = (current < minVal * current) ? current : minVal * current;

            if (maxVal > maxProduct) {
                maxProduct = maxVal;
            }
        }

        return maxProduct;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int maxVal = nums[0], minVal = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {

                std::swap(maxVal, minVal);
            }

            maxVal = std::max(nums[i], maxVal * nums[i]);
            minVal = std::min(nums[i], minVal * nums[i]);

            maxProduct = std::max(maxProduct, maxVal);
        }

        return maxProduct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
