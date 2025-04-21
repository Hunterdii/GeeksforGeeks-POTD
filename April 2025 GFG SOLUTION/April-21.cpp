//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function template for C++

class Solution {
  public:
    int missingNum(vector<int>& a) {
        int n = a.size() + 1, x = 0;
        for (int i = 0; i < n - 1; i++) x ^= a[i];
        for (int i = 1; i <= n; i++) x ^= i;
        return x;
    }
};


2)
class Solution{
public:
    int missingNum(vector<int>&a){
        int x=0,n=a.size()+1;
        for(int i=0;i<a.size();++i) x^=a[i]^(i+1);
        return x^n;
    }
};

3)
class Solution {
public:
    int missingNum(vector<int>& a) {
        long long n = a.size() + 1;
        long long total = n * (n + 1) / 2;
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        return total - sum;
    }
};


4)
class Solution {
public:
    int missingNum(vector<int>& a) {
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            if (a[i] != i + 1) return i + 1;
        return a.size() + 1;
    }
};


5)
class Solution {
public:
    int missingNum(vector<int>& a) {
        int n = a.size();
        vector<bool> seen(n + 2, false);
        for (int x : a) seen[x] = true;
        for (int i = 1; i <= n + 1; i++)
            if (!seen[i]) return i;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
