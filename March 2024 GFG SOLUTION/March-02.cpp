//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        std::unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            map[a[i]]++;
            if(map[a[i]] == k)
                return a[i];
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
