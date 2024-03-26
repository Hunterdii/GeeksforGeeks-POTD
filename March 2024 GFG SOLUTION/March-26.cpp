//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string add(const string& num1, const string& num2) {
        string result;
        int carry = 0;
        int i = num1.length() - 1, j = num2.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool isAdditiveSequence(const string& s) {
        int n = s.size();
        if (s[0] == '0') return false;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string num1 = s.substr(0, i);
                string num2 = s.substr(i, j - i);
                if (isValid(s.substr(j), num1, num2))
                    return true;
            }
        }
        return false;
    }

private:
    bool isValid(const string& s, const string& num1, const string& num2) {
        if (s.empty()) return true;
        string sum = add(num1, num2);
        if (s.find(sum) == 0)
            return isValid(s.substr(sum.size()), num2, sum);
        return false;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends
