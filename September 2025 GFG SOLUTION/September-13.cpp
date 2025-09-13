class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int h = 1, v = 1, i = 0, j = 0, cost = 0;
        while (i < x.size() && j < y.size()) {
            if (x[i] > y[j]) cost += x[i++] * h, v++;
            else cost += y[j++] * v, h++;
        }
        while (i < x.size()) cost += x[i++] * h;
        while (j < y.size()) cost += y[j++] * v;
        return cost;
    }
};

2)
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,char>> pq;
        for (int cost : x) pq.push({cost, 'h'});
        for (int cost : y) pq.push({cost, 'v'});
        
        int h = 1, v = 1, total = 0;
        while (!pq.empty()) {
            auto [cost, type] = pq.top(); pq.pop();
            if (type == 'h') total += cost * h, v++;
            else total += cost * v, h++;
        }
        return total;
    }
};

3)
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int cost = 0, pieces_h = 1, pieces_v = 1;
        int i = 0, j = 0;
        
        while (i < x.size() || j < y.size()) {
            bool take_horizontal = (j >= y.size()) || 
                                 (i < x.size() && x[i] >= y[j]);
            
            if (take_horizontal) {
                cost += x[i] * pieces_h;
                pieces_v++;
                i++;
            } else {
                cost += y[j] * pieces_v;
                pieces_h++;
                j++;
            }
        }
        return cost;
    }
};

4)
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        vector<pair<int, bool>> cuts;
        for (int cost : x) cuts.push_back({cost, true});
        for (int cost : y) cuts.push_back({cost, false});
        
        sort(cuts.rbegin(), cuts.rend());
        
        int h_pieces = 1, v_pieces = 1, total = 0;
        for (auto [cost, is_horizontal] : cuts) {
            if (is_horizontal) {
                total += cost * h_pieces;
                v_pieces++;
            } else {
                total += cost * v_pieces;
                h_pieces++;
            }
        }
        return total;
    }
};
