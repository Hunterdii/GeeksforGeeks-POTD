class Solution {
public:
    int findMoves(vector<int>& c, vector<int>& p) {
        sort(c.begin(), c.end());
        sort(p.begin(), p.end());
        int res = 0, n = c.size();
        for (int i = 0; i < n; i++) res += abs(c[i] - p[i]);
        return res;
    }
};

2)
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        priority_queue<int, vector<int>, greater<int>> c(chairs.begin(), chairs.end());
        priority_queue<int, vector<int>, greater<int>> p(passengers.begin(), passengers.end());
        int moves = 0;
        while (!c.empty()) {
            moves += abs(c.top() - p.top());
            c.pop();
            p.pop();
        }
        return moves;
    }
};

3)
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        return accumulate(chairs.begin(), chairs.end(), 0, 
            [&, i = 0](int sum, int chair) mutable {
                return sum + abs(chair - passengers[i++]);
            });
    }
};

4)
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        int i = 0, j = 0, total = 0;
        while (i < chairs.size() && j < passengers.size()) {
            total += abs(chairs[i++] - passengers[j++]);
        }
        return total;
    }
};
