//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int xor_all = 0, xor1 = 0, xor2 = 0;
        for (int i = 0; i < n; i++) {
            xor_all ^= arr[i];   
            xor_all ^= (i + 1);  
        }
        int set_bit = xor_all & ~(xor_all - 1);
        for (int i = 0; i < n; i++) {
            if (arr[i] & set_bit)  
                xor1 ^= arr[i];
            else                    
                xor2 ^= arr[i];

            if ((i + 1) & set_bit)
                xor1 ^= (i + 1);
            else                
                xor2 ^= (i + 1);
        }
        int repeating, missing;
        for (int i = 0; i < n; i++) {
            if (arr[i] == xor1) {
                repeating = xor1;
                missing = xor2;
                break;
            } else if (arr[i] == xor2) {
                repeating = xor2;
                missing = xor1;
                break;
            }
        }

        return {repeating, missing};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
