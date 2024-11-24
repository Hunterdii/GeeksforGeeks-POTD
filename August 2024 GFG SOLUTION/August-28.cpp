//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int, int> freqMap;
        vector<pair<int, int>> freqVec;
        for (int num : arr) {
            freqMap[num]++;
        }
        for (const auto& entry : freqMap) {
            freqVec.emplace_back(entry.first, entry.second);
        }
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        vector<int> result;
        for (const auto& entry : freqVec) {
            result.insert(result.end(), entry.second, entry.first);
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
