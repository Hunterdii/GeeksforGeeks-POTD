class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        return V * (V - 1) / 2 - edges.size();
    }
};

2)
class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        return (V - 1) * V / 2 - static_cast<int>(edges.size());
    }
};

3)
class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        int maxCapacity = (V * V - V) >> 1;
        return maxCapacity - edges.size();
    }
};

4)
class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        int used = edges.size();
        int total = V * (V - 1) / 2;
        int available = total - used;
        return available;
    }
};
