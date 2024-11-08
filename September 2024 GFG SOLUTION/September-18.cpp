//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool ispar(string x) {
        stack<char> s;
        for (char c : x) {
            switch(c) {
                case '(': case '{': case '[':
                    s.push(c);
                    break;
                case ')':
                    if (s.empty() || s.top() != '(') return false;
                    s.pop();
                    break;
                case '}':
                    if (s.empty() || s.top() != '{') return false;
                    s.pop();
                    break;
                case ']':
                    if (s.empty() || s.top() != '[') return false;
                    s.pop();
                    break;
            }
        }
        return s.empty();
    }
};



//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
