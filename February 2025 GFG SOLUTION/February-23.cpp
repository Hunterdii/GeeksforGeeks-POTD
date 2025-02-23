//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> s;
        vector<int> res(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i]) s.pop();
            res[i] = s.empty() ? -1 : s.top();
            s.push(arr[i]);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        list<int> indices;
        vector<int> res(arr.size(), -1);
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!indices.empty() && arr[indices.back()] <= arr[i]) indices.pop_back();
            if (!indices.empty()) res[i] = arr[indices.back()];
            indices.push_back(i);
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends
