//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:	
    vector<string> NBitBinary(int n)
    {
        vector<string> result;
        string out = "";
        int on = 0, ze = 0;
        
        function<void(string,int,int,int)> util = [&](string out, int on, int ze, int n) {
            if (n == 0) {
                result.push_back(out);
                return;
            }
            if (on == ze) {
                util(out + "1", on + 1, ze, n - 1);
            }
            if (on > ze) {
                util(out + "1", on + 1, ze, n - 1);
                util(out + "0", on, ze + 1, n - 1);
            }
        };
        
        util(out, on, ze, n);
        return result;
    }
};




//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
