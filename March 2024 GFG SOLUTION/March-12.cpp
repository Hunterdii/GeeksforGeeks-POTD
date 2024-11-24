//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution
{
public:
    vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B, ll m)
    {
        int size = A.size();
        vector<vector<ll>> result(size, vector<ll>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    result[i][j] += (A[i][k] % m) * (B[k][j] % m);
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }

    long long genFibNum(ll a, ll b, ll c, ll n, ll m)
    {
        if (n <= 2)
            return 1LL % m;
        vector<vector<ll>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<ll>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0)
        {
            if (n & 1)
                res = multiply(res, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends
