//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> ans;
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
        
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else if (arr1[i] > arr2[j]) {
                ans.push_back(arr2[j]);
                j++;
            } else {
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        
        while (i < n) {
            ans.push_back(arr1[i]);
            i++;
        }
        
        while (j < m) {
            ans.push_back(arr2[j]);
            j++;
        }
        
        // Remove duplicates
        auto it = unique(ans.begin(), ans.end());
        ans.resize(distance(ans.begin(), it));
        
        return ans; 
    }
};



//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
