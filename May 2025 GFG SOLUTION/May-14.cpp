//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; ++i) {
            string temp;
            for (int j = 0; j < res.size(); ) {
                int k = j;
                while (k < res.size() && res[k] == res[j]) ++k;
                temp += to_string(k - j) + res[j];
                j = k;
            }
            res = temp;
        }
        return res;
    }
};

2)
class Solution {
  public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            ostringstream oss;
            int count = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    ++count;
                } else {
                    oss << count << result[j - 1];
                    count = 1;
                }
            }
            oss << count << result.back();
            result = oss.str();
        }
        return result;
    }
};

3)
class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result;
        for (int i = 0; i < prev.size(); ) {
            int count = 1;
            while (i + count < prev.size() && prev[i + count] == prev[i]) ++count;
            result += to_string(count) + prev[i];
            i += count;
        }
        return result;
    }
};

4)
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string result = "";
        int count = 1;

        for (int i = 1; i < prev.size(); ++i) {
            if (prev[i] == prev[i - 1]) {
                count++;
            } else {
                result += to_string(count) + prev[i - 1];
                count = 1;
            }
        }

        result += to_string(count) + prev.back();
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
