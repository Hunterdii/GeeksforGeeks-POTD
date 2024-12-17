//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
1)
class Solution {
public:

    bool canPlaceCows(vector<int>& stalls, int k, int dist) {
        int count = 1; 
        int lastPlaced = stalls[0]; 

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPlaced >= dist) {
                count++;
                lastPlaced = stalls[i];
            }
            if (count >= k) return true; 
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end()); 

        int low = 1; 
        int high = stalls.back() - stalls.front(); 

        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlaceCows(stalls, k, mid)) {
                result = mid; 
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return result;
    }
};
2)
class Solution {
public:
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls.front(), mid;

        while (low <= high) {
            mid = low + (high - low) / 2;
            int count = 1, last = stalls[0];
            for (int i = 1; i < stalls.size(); i++)
                if (stalls[i] - last >= mid) { count++; last = stalls[i]; }
            if (count >= k) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
