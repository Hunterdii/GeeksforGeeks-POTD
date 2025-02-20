//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    multiset<int> left, right;
    
    void insert(int num) {
        if (left.empty() || num <= *left.rbegin()) left.insert(num);
        else right.insert(num);

        if (left.size() > right.size() + 1) right.insert(*left.rbegin()), left.erase(prev(left.end()));
        else if (right.size() > left.size()) left.insert(*right.begin()), right.erase(right.begin());
    }

    vector<double> getMedian(vector<int>& arr) {
        vector<double> res;
        for (int num : arr) {
            insert(num);
            res.push_back(left.size() > right.size() ? *left.rbegin() : (*left.rbegin() + *right.begin()) / 2.0);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<double> getMedian(vector<int>& arr) {
        vector<int> sorted;
        vector<double> res;

        for (int num : arr) {
            sorted.insert(lower_bound(sorted.begin(), sorted.end(), num), num);
            int n = sorted.size();
            res.push_back(n % 2 ? sorted[n / 2] : (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0);
        }
        return res;
    }
};

3)
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<double> result;

        for (int num : arr) {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            result.push_back(maxHeap.size() > minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0);
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

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
