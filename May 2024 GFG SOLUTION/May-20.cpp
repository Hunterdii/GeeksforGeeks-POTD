//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long int PowMod(long long int a, long long int b, long long int m) {
        if (b == 0) return 1; // Base case: a^0 is 1

        a %= m;
        long long half = PowMod(a, b / 2, m);

        if (b % 2 == 0) {
            return (half * half) % m;
        } else {
            return (((half * half) % m) * a) % m;
        }
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends up
