//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int count = 0, candidate;
        for (int num : arr) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        count = 0;
        for (int num : arr) if (num == candidate) count++;
        return count > arr.size() / 2 ? candidate : -1;
    }
};

2)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        for (auto &p : freq)
            if (p.second > arr.size() / 2)
                return p.first;
        return -1;
    }
};

3)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int candidate = arr[arr.size() / 2];
        int count = count_if(arr.begin(), arr.end(), [&](int x){ return x == candidate; });
        return count > arr.size() / 2 ? candidate : -1;
    }
};

4)
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size(), result = 0;
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int num : arr)
                if ((num >> i) & 1) bitCount++;
            if (bitCount > n / 2) result |= (1 << i);
        }
        int count = count_if(arr.begin(), arr.end(), [&](int x){ return x == result; });
        return count > n / 2 ? result : -1;
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
