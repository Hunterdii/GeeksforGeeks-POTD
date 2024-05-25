//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long max_Books(int a[], int n, int k) {
        long long max_sum = 0, current_sum = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                current_sum += a[i];
                max_sum = std::max(max_sum, current_sum);
            } else {
                current_sum = 0;
            }
        }
        return max_sum;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
