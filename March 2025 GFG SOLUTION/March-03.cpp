//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQ, maxQ;
        int n = arr.size(), start = 0, resStart = 0, resEnd = 0;
        for (int end = 0; end < n; end++) {
            while (!minQ.empty() && arr[minQ.back()] > arr[end]) minQ.pop_back();
            while (!maxQ.empty() && arr[maxQ.back()] < arr[end]) maxQ.pop_back();
            minQ.push_back(end), maxQ.push_back(end);
            while (arr[maxQ.front()] - arr[minQ.front()] > x) {
                if (minQ.front() == start) minQ.pop_front();
                if (maxQ.front() == start) maxQ.pop_front();
                start++;
            }
            if (end - start > resEnd - resStart) resStart = start, resEnd = end;
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resEnd + 1);
    }
};

2)
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        priority_queue<pair<int, int>> maxHeap; // max element
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // min element
        int start = 0, resStart = 0, resEnd = 0;
        
        for (int end = 0; end < arr.size(); ++end) {
            maxHeap.emplace(arr[end], end);
            minHeap.emplace(arr[end], end);
            
            while (!maxHeap.empty() && !minHeap.empty() && maxHeap.top().first - minHeap.top().first > x) {
                start = min(maxHeap.top().second, minHeap.top().second) + 1;
                while (!maxHeap.empty() && maxHeap.top().second < start) maxHeap.pop();
                while (!minHeap.empty() && minHeap.top().second < start) minHeap.pop();
            }
            
            if (end - start > resEnd - resStart) resStart = start, resEnd = end;
        }
        
        return vector<int>(arr.begin() + resStart, arr.begin() + resEnd + 1);
    }
};

3)
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        multiset<int> window;
        int start = 0, resStart = 0, resLen = 0;
        for (int end = 0; end < arr.size(); end++) {
            window.insert(arr[end]);
            while (*window.rbegin() - *window.begin() > x) window.erase(window.find(arr[start++]));
            if (end - start + 1 > resLen) resStart = start, resLen = end - start + 1;
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resStart + resLen);
    }
};

4)
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size(), maxLen = 0, resStart = 0;
        for (int i = 0; i < n; i++) {
            int minVal = arr[i], maxVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]), maxVal = max(maxVal, arr[j]);
                if (maxVal - minVal > x) break;
                if (j - i + 1 > maxLen) resStart = i, maxLen = j - i + 1;
            }
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resStart + maxLen);
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
