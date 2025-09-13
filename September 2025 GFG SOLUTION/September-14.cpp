class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) start = i + 1, curr = 0;
        }
        return total >= 0 ? start : -1;
    }
};

2)
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};

3)
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            sum += diff;
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};

4)
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        int n = gas.size();
        for (int i = 0; i < 2 * n; i++) {
            int index = i % n;
            int diff = gas[index] - cost[index];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = index + 1;
                curr = 0;
                if (start >= n) break;
            }
        }
        return total >= 0 ? start : -1;
    }
};
