//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
1)
class Solution {
public:
    long long sumSubstrings(string s) {
        long long mod = 1e9 + 7;
        long long r = 1, res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res = (res + ((s[i] - '0') * (i + 1) * r) % mod) % mod;
            r = (r * 10 + 1) % mod;
        }
        return res;
    }
};
2)
class Solution {
public:
    long long sumSubstrings(string s) {
        int mod = pow(10, 9) + 7; // Calculate modulo value dynamically
        long long int r = 1, res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res = (res + ((s[i] - '0') * (i + 1) * r) % mod) % mod;
            r = (r * 10 + 1) % mod;
        }
        return res;
    }
};
3)
class Solution {
public:
    long long sumSubstrings(string s) {
        long long mod = 1e9 + 7;
        long long result = 0;
        long long multiplier = 1;
        long long positionSum = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            positionSum = (positionSum + (s[i] - '0') * multiplier) % mod;
            result = (result + positionSum) % mod;
            multiplier = (multiplier * 10 + 1) % mod;
        }

        return result;
    }
};
4)
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
       long long int mod=1e9+7;
        long long int r=1,res=0;
            for(int i=s.size()-1;i>=0;i--){
            // long long int  
            res=(res+((s[i]-'0')*(i+1)*r)%mod)%mod;
            res%=mod;
            r=(r*10+1)%mod;
            r%=mod;
            
        }
        return(res);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
