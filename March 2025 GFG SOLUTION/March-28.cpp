//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> activities;
        for (int i = 0; i < start.size(); i++) activities.push_back({finish[i], start[i]});
        sort(activities.begin(), activities.end());
        int count = 1, end = activities[0].first;
        for (int i = 1; i < activities.size(); i++) {
            if (activities[i].second > end) {
                count++;
                end = activities[i].first;
            }
        }
        return count;
    }
};



2)
class Solution {
public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < start.size(); i++) 
            arr.emplace_back(finish[i], start[i]);
        sort(arr.begin(), arr.end());
        int ans = 0, finishtime = -1;
        for (auto &activity : arr) 
            if (activity.second > finishtime) 
                finishtime = activity.first, ans++;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
