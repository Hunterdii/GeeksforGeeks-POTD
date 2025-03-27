//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int platforms = 0, maxPlatforms = 0, i = 0, j = 0;
        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
                platforms++, i++;
                maxPlatforms = max(maxPlatforms, platforms);
            } else {
                platforms--, j++;
            }
        }
        return maxPlatforms;
    }
};

2)
class Solution {
  public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        int i = 0, j = 0, cnt = 0, ans = 0, n = a.size();
        while(i < n && j < n)
            a[i] <= d[j] ? (cnt++, ans = max(ans, cnt), i++) : (cnt--, j++);
        return ans;
    }
};

3)
class Solution {
public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int platforms = 0, maxPlatforms = 0;

        for (int i = 0; i < a.size(); i++) {
            while (!pq.empty() && pq.top() < a[i]) {
                pq.pop();
                platforms--;
            }
            pq.push(d[i]);
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};

4)
class Solution {
public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        map<int, int> timeline;

        for (int i = 0; i < a.size(); i++) {
            timeline[a[i]]++;
            timeline[d[i] + 1]--;
        }

        int platforms = 0, maxPlatforms = 0;
        for (auto it = timeline.begin(); it != timeline.end(); ++it) {
            platforms += it->second;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
