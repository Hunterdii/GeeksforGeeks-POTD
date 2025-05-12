//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> avail;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> cnt(n);
        for(int i=0;i<n;i++) avail.push(i);
        for(auto &m:meetings){
            long long s=m[0], e=m[1];
            while(!busy.empty() && busy.top().first<=s){
                avail.push(busy.top().second);
                busy.pop();
            }
            int r = avail.empty() ? (busy.top().second) : avail.top();
            if(avail.empty()) {
                long long t=busy.top().first;
                busy.pop();
                busy.push({t+e-s, r});
            } else {
                avail.pop();
                busy.push({e, r});
            }
            cnt[r]++;
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};

2)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(n, 0); 
        for (int i = 0; i < n; ++i)
            available.push(i);
        for (const auto& m : meetings) {
            long long start = m[0], end = m[1];
            long long duration = end - start;
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            int room;
            long long actualStart;

            if (!available.empty()) {
                room = available.top(); available.pop();
                actualStart = start;
            } else {
                auto next = busy.top(); busy.pop();
                room = next.second;
                actualStart = next.first;
            }

            long long actualEnd = actualStart + duration;
            busy.push({actualEnd, room});
            count[room]++;
        }
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxRoom]) maxRoom = i;
        }

        return maxRoom;
    }
};

3)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        sort(meet.begin(), meet.end(),
             [](const vector<int>& A, const vector<int>& B){
                 return A[0] < B[0];
             });
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long,int>,
                      vector<pair<long long,int>>,
                      greater<pair<long long,int>>> busy;
        priority_queue<pair<long long,long long>,
                      vector<pair<long long,long long>>,
                      greater<pair<long long,long long>>> waiting;
        vector<int> cnt(n, 0);
        int m = meet.size();
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        int idx = 0;
        long long T = 0;
        while (idx < m || !busy.empty() || !waiting.empty()) {
            long long nxtT = LLONG_MAX;
            if (idx < m) {
                long long s = meet[idx][0];
                if (s < nxtT) nxtT = s;
            }
            if (!busy.empty() && busy.top().first < nxtT) {
                nxtT = busy.top().first;
            }
            T = nxtT;
            while (!busy.empty() && busy.top().first <= T) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }
            while (idx < m && meet[idx][0] == T) {
                long long orig = meet[idx][0];
                long long dur  = meet[idx][1] - meet[idx][0];
                waiting.push(make_pair(orig, dur));
                idx++;
            }
            while (!freeRooms.empty() && !waiting.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                pair<long long,long long> w = waiting.top();
                waiting.pop();
                long long dur = w.second;
                busy.push(make_pair(T + dur, room));
                cnt[room]++;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i)
            if (cnt[i] > cnt[ans]) ans = i;
        return ans;
    }
};

4)
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(),
             [](auto &A, auto &B){ return A[0] < B[0]; });
        priority_queue<int, vector<int>, greater<int>> avail;
        priority_queue<pair<long long,int>,
                      vector<pair<long long,int>>,
                      greater<pair<long long,int>>> busy;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) avail.push(i);
        for (auto &m : meetings) {
            long long s = m[0], e = m[1];
            while (!busy.empty() && busy.top().first <= s) {
                avail.push(busy.top().second);
                busy.pop();
            }
            
            int room;
            if (!avail.empty()) {
                room = avail.top(); avail.pop();
                busy.push({e, room});
            } else {
                auto pr = busy.top(); busy.pop();
                room = pr.second;
                long long newEnd = pr.first + (e - s);
                busy.push({newEnd, room});
            }
            cnt[room]++;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i)
            if (cnt[i] > cnt[ans]) ans = i;
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
