//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> result;
    int row[10], k = 0;

    bool place(int r, int c) {
        for (int prev = 0; prev < c; prev++) {
            if (row[prev] == r || abs(row[prev] - r) == abs(prev - c)) {
                return false;
            }
        }
        return true;
    }
    void bt(int c, int n) {
        if (c == n) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(row[i] + 1);
            }
            result.push_back(v);
            return; 
        }
        for (int i = 0; i < n; i++) {
            if (place(i, c)) {
                row[c] = i;
                bt(c + 1, n);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        result.clear();
        bt(0, n);
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
