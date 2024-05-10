//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(vector<int>& arr, int target, int start, vector<int>& temp, vector<vector<int>>& result) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i < arr.size(); i++) {
            if(i > start && arr[i] == arr[i - 1])
                continue;

            if(arr[i] > target)
                break;

            temp.push_back(arr[i]);
            solve(arr, target - arr[i], i + 1, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(arr, k, 0, temp, result);
        return result;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
