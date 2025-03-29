//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> jobSequencing(vector<int>& d, vector<int>& p) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < d.size(); ++i) jobs.emplace_back(d[i], p[i]);
        sort(jobs.begin(), jobs.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& job : jobs) {
            if (job.first > pq.size()) pq.push(job.second);
            else if (pq.top() < job.second) pq.pop(), pq.push(job.second);
        }

        int cnt = pq.size(), tot = 0;
        while (!pq.empty()) tot += pq.top(), pq.pop();
        return {cnt, tot};
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
