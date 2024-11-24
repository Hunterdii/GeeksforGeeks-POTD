//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
       int findCrossOver(std::vector<int>& arr, int low, int high, int x) {
        
        if (arr[high] <= x) return high;
        if (arr[low] > x) return low;

        int mid = (low + high) / 2;

       
        if (arr[mid] <= x && arr[mid + 1] > x) return mid;
        else if (arr[mid] < x) return findCrossOver(arr, mid + 1, high, x);
        return findCrossOver(arr, low, mid - 1, x);
    }

    std::vector<int> printKClosest(std::vector<int>& arr, int n, int k, int x) {
  
        int id1 = findCrossOver(arr, 0, n - 1, x);

      
        int id2 = id1 + 1;

   
        if (id1 >= 0 && arr[id1] == x) id1--;

        std::vector<int> ans;
        for (int i = 0; i < k; i++) {
           
            if (id1 >= 0 && id2 < n) {
                int val1 = x - arr[id1];
                int val2 = arr[id2] - x;
               
                if (val1 < val2) {
                    ans.push_back(arr[id1]);
                    id1--;
                } else {
                    ans.push_back(arr[id2]);
                    id2++;
                }
            } else if (id1 >= 0) {
                ans.push_back(arr[id1]);
                id1--;
            } else {
                ans.push_back(arr[id2]);
                id2++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
