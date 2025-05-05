//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        for(int i = 0; i < arr.size(); ++i)
            if(arr[i] == target) return i;
        return -1;
    }
};


2)
#include <algorithm>
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        auto it = find(arr.begin(), arr.end(), target);
        return it == arr.end() ? -1 : it - arr.begin();
    }
};


3)
#include <unordered_map>

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
        }
        return mp.count(target) ? mp[target] : -1;
    }
};

4)
#include <unordered_map>
#include <algorithm>

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < arr.size(); ++i)
            if (indexMap.find(arr[i]) == indexMap.end())
                indexMap[arr[i]] = i;

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int l = 0, r = sortedArr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (sortedArr[m] == target)
                return indexMap[target];
            else if (sortedArr[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};


5)
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) return mid;
            if (mid > l && arr[mid - 1] == target) return mid - 1;
            if (mid < r && arr[mid + 1] == target) return mid + 1;

            if (arr[mid] > target) r = mid - 2;
            else l = mid + 2;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
