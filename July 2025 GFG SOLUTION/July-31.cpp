class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> events;
        for (auto& i : intervals) {
            events[i[0]]++;
            events[i[1] + 1]--;
        }
        int count = 0, result = -1;
        for (auto& e : events) {
            if (e.second > 0) {
                count += e.second;
                if (count >= k) result = e.first;
            } else {
                if (count >= k) result = e.first - 1;
                count += e.second;
            }
        }
        return result;
    }
};

2)
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        set<int> coords;
        for (auto& i : intervals) {
            coords.insert(i[0]);
            coords.insert(i[1] + 1);
        }
        vector<int> sorted_coords(coords.begin(), coords.end());
        vector<int> diff(sorted_coords.size(), 0);
        
        for (auto& i : intervals) {
            int start_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[0]) - sorted_coords.begin();
            int end_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[1] + 1) - sorted_coords.begin();
            diff[start_idx]++;
            if (end_idx < diff.size()) diff[end_idx]--;
        }
        
        int count = 0, result = -1;
        for (int i = 0; i < diff.size(); i++) {
            count += diff[i];
            if (count >= k && i + 1 < sorted_coords.size()) 
                result = sorted_coords[i + 1] - 1;
        }
        return result;
    }
};

3)
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        vector<pair<int, int>> events;
        for (auto& i : intervals) {
            events.push_back({i[0], 1});
            events.push_back({i[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        
        int count = 0, result = -1, prev_pos = -1;
        for (auto& e : events) {
            if (count >= k && e.first > prev_pos) {
                result = e.first - 1;
            }
            count += e.second;
            prev_pos = e.first;
        }
        return result;
    }
};

4)
class Solution {
    vector<int> tree, lazy;
    void build(int node, int start, int end) {
        if (start == end) tree[node] = lazy[node] = 0;
        else {
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            tree[node] = lazy[node] = 0;
        }
    }
    void updateLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void updateRange(int node, int start, int end, int l, int r, int val) {
        updateLazy(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            updateLazy(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
    }
    int query(int node, int start, int end, int idx) {
        updateLazy(node, start, end);
        if (start == end) return tree[node];
        int mid = (start + end) / 2;
        if (idx <= mid) return query(2*node, start, mid, idx);
        return query(2*node+1, mid+1, end, idx);
    }
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        set<int> coords;
        for (auto& i : intervals) {
            coords.insert(i[0]);
            coords.insert(i[1]);
        }
        vector<int> sorted_coords(coords.begin(), coords.end());
        int n = sorted_coords.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
        for (auto& i : intervals) {
            int start_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[0]) - sorted_coords.begin();
            int end_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[1]) - sorted_coords.begin();
            updateRange(1, 0, n - 1, start_idx, end_idx, 1);
        }
        int result = -1;
        for (int i = 0; i < n; i++) {
            if (query(1, 0, n - 1, i) >= k) {
                result = sorted_coords[i];
            }
        }
        return result;
    }
};

5)
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        if (intervals.empty()) return -1;
        
        int min_coord = INT_MAX, max_coord = INT_MIN;
        for (auto& i : intervals) {
            min_coord = min(min_coord, i[0]);
            max_coord = max(max_coord, i[1]);
        }
        
        int result = -1;
        for (int pos = min_coord; pos <= max_coord; pos++) {
            int count = 0;
            for (auto& i : intervals) {
                if (pos >= i[0] && pos <= i[1]) count++;
            }
            if (count >= k) result = pos;
        }
        return result;
    }
};
