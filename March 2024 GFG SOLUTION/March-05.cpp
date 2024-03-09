//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
       int i=0,j=n-1;
       int ans = 0;
       
       while(i <= j){
           if(a[i]<=a[j]){
               ans = max(ans,j-i);
               i++;
               j = n-1;
           }
           else{
               j--;
           }
       }
       
       return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
