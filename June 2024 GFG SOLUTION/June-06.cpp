//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
#define ll unsigned long long

class Solution {
public:
    long long max_sum(int a[], int n) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        ll currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += (ll)i * a[i];
        }
        ll maxi = currSum;
        for (int i = 1; i < n; ++i) {
            currSum = currSum + sum - (ll)n * a[n - i];
            maxi = max(maxi, currSum);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends
