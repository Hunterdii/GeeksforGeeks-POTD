//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size();
        if (n == 0) return str;  

        if (str[n - 1] - '0' <= 5) {
            str[n - 1] = '0';  
            return str;  
        } else {

            str[n - 1] = '0';  
            int i = n - 2;

            while (i >= 0) {
                if (str[i] != '9') {
                    str[i] = (char)((str[i] - '0') + 1 + '0');  
                    return str;
                }

                str[i] = '0';
                i--;
            }

            return "1" + str;
        }
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends
