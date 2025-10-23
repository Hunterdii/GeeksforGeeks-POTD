class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(),
            [](auto& a, auto& b) { return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]; });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

2)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        for(int i = 0; i < points.size(); i++)
            minHeap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1], i});
        vector<vector<int>> res;
        while(k--) {
            res.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

4)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        function<void(int,int)> quickselect = [&](int l, int r) {
            if(l >= r) return;
            int p = l, i = l;
            for(int j = l; j < r; j++)
                if(points[j][0]*points[j][0]+points[j][1]*points[j][1] < points[r][0]*points[r][0]+points[r][1]*points[r][1])
                    swap(points[i++], points[j]);
            swap(points[i], points[r]);
            if(i < k) quickselect(i+1, r);
            else if(i > k) quickselect(l, i-1);
        };
        quickselect(0, points.size()-1);
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};

5)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            if(maxHeap.size() < k) maxHeap.push({dist, p});
            else if(dist < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({dist, p});
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
