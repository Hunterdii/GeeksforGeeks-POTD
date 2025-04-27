//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string multiplyStrings(string num1, string num2) {
        int sign=1;
        if(num1[0]=='-') sign*=-1,num1=num1.substr(1);
        if(num2[0]=='-') sign*=-1,num2=num2.substr(1);
        int n=num1.size(),m=num2.size();
        if(n==0||m==0) return "0";
        vector<int> res(n+m,0);
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--)
                res[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
        for(int i=n+m-1;i>0;i--){
            res[i-1]+=res[i]/10;
            res[i]%=10;
        }
        string ans;
        int i=0;
        while(i<res.size()&&res[i]==0) i++;
        for(;i<res.size();i++) ans+=res[i]+'0';
        if(ans.empty()) return "0";
        return sign==-1?"-"+ans:ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
