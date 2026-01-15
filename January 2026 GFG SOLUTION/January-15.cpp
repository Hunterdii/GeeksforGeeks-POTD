class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size(), total = n, i = 1;
        while (i < n) {
            if (arr[i] == arr[i - 1]) { i++; continue; }
            int peak = 0;
            while (i < n && arr[i] > arr[i - 1]) total += ++peak, i++;
            int valley = 0;
            while (i < n && arr[i] < arr[i - 1]) total += ++valley, i++;
            total -= min(peak, valley);
        }
        return total;
    }
};

2)
class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[i - 1]) left[i] = left[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (arr[i] > arr[i + 1]) right[i] = right[i + 1] + 1;
        int total = 0;
        for (int i = 0; i < n; i++) total += max(left[i], right[i]);
        return total;
    }
};

3)
class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[i - 1]) candies[i] = candies[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (arr[i] > arr[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        int total = 0;
        for (int x : candies) total += x;
        return total;
    }
};
