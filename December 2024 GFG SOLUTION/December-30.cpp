//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++
class Solution {
  public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s(a.begin(), a.end()); 
        s.insert(b.begin(), b.end());            
        return s.size();    
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.findUnion(a, b) << endl;
        cout << '~' << endl;
    }

    return 0;
}
// } Driver Code Ends
