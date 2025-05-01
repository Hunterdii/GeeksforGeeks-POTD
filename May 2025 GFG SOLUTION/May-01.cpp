//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row(n);
        row[0]=1;
        for(int i=1;i<n;++i) row[i]=row[i-1]*(n-i)/i;
        return row;
    }
};

2)
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<long long> fact(n);
        fact[0]=1;
        for(int i=1;i<n;++i) fact[i]=fact[i-1]*i;
        vector<int> row(n);
        for(int k=0;k<n;++k)
            row[k]=fact[n-1]/(fact[k]*fact[n-1-k]);
        return row;
    }
};

3)
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<vector<int>> T(n, vector<int>(n));
        for(int i=0;i<n;++i){
            T[i][0]=T[i][i]=1;
            for(int j=1;j<i;++j) T[i][j]=T[i-1][j-1]+T[i-1][j];
        }
        return T[n-1];
    }
};

4)
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> prev={1}, curr;
        for(int i=2;i<=n;++i){
            curr.assign(i,1);
            for(int j=1;j<i-1;++j) curr[j]=prev[j-1]+prev[j];
            prev.swap(curr);
        }
        return prev;
    }
};




//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
