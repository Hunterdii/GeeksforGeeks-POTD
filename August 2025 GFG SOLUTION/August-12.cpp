class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), min = 0, max = 0;
        for (int i = 0, rem = n; i < rem; i++, rem -= k) min += prices[i];
        for (int j = n - 1, idx = -1; j > idx; j--, idx += k) max += prices[j];
        return {min, max};
    }
};

2)
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), minCost = 0, maxCost = 0;
        for (int i = 0, remaining = n; i < remaining; i++, remaining -= k) 
            minCost += prices[i];
        for (int j = n - 1, index = -1; j > index; j--, index += k) 
            maxCost += prices[j];
        return {minCost, maxCost};
    }
};

3)
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), minCost = 0, maxCost = 0;
        int purchases = (n + k) / (k + 1); 
        for (int i = 0; i < purchases; i++) minCost += prices[i];
        for (int i = n - purchases; i < n; i++) maxCost += prices[i];
        return {minCost, maxCost};
    }
};

4)
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), minCost = 0, maxCost = 0;
        int i = 0, remaining = n;
        while (i < remaining) {
            minCost += prices[i];
            i++;
            remaining -= k;
        }
        int j = n - 1, lowerBound = -1;
        while (j > lowerBound) {
            maxCost += prices[j];
            j--;
            lowerBound += k;
        }
        return {minCost, maxCost};
    }
};
