//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    string minSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string num1, num2;
        bool toggle = true;
        
        for (int i = 0; i < n; i++) {
            if (toggle) {
                if (!(arr[i] == 0 && num1.empty())) 
                    num1 += to_string(arr[i]);
            } else {
                if (!(arr[i] == 0 && num2.empty())) 
                    num2 += to_string(arr[i]);
            }
            toggle = !toggle;
        }

        if (num1.empty()) num1 = "0";
        if (num2.empty()) num2 = "0";
        return findSum(num1, num2);
    }

private:
    string findSum(const string& str1, const string& str2) {
        int n1 = str1.size(), n2 = str2.size();
        int carry = 0;
        string result;
        
        for (int i = 0; i < max(n1, n2) || carry; i++) {
            int digit1 = i < n1 ? str1[n1 - i - 1] - '0' : 0;
            int digit2 = i < n2 ? str2[n2 - i - 1] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
