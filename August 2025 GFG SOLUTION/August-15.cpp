class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) result.push_back(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        result.push_back(newInterval);
        while (i < n) result.push_back(intervals[i++]);
        
        return result;
    }
};

2)
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, 
            [](const vector<int>& a, const vector<int>& b) { return a[1] < b[0]; });
        
        res.insert(res.end(), intervals.begin(), it);
        
        while (it != intervals.end() && (*it)[0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], (*it)[0]);
            newInterval[1] = max(newInterval[1], (*it)[1]);
            ++it;
        }
        
        res.push_back(newInterval);
        res.insert(res.end(), it, intervals.end());
        return res;
    }
};

3)
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        auto it = intervals.begin();
        
        while (it != intervals.end() && (*it)[1] < newInterval[0]) 
            ans.push_back(*it++);
        
        while (it != intervals.end() && (*it)[0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], (*it)[0]), max(newInterval[1], (*it)[1])};
            ++it;
        }
        ans.push_back(newInterval);
        ans.insert(ans.end(), it, intervals.end());
        
        return ans;
    }
};

4)
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = 0, end = intervals.size() - 1;
        
        while (start <= end && intervals[start][1] < newInterval[0]) start++;
        while (end >= start && intervals[end][0] > newInterval[1]) end--;
        
        if (start <= end) {
            newInterval[0] = min(newInterval[0], intervals[start][0]);
            newInterval[1] = max(newInterval[1], intervals[end][1]);
            intervals.erase(intervals.begin() + start, intervals.begin() + end + 1);
        }
        
        intervals.insert(intervals.begin() + start, newInterval);
        return intervals;
    }
};
