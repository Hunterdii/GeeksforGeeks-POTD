//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution 
{ 
    public: 
        vector <int> search(string pattern, string text) 
        { 
            //code here. 
            int n = text.size(); 
            int m = pattern.size(); 
            vector<int> ans; 
             
            for(int i = 0; i<n-m+1; i++){ 
                //check if first and last character match then only check whole string to reduce time complexity 
                if(pattern[0]==text[i] && pattern[m-1]==text[i+m-1]){ 
                     
                    if(pattern==text.substr(i,m)){ 
                        ans.push_back(i+1); 
                    } 
                } 
            } 
             
            return ans; 
        } 
      
}; 

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
