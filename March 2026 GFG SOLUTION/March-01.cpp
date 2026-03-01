class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int pos = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] != 0) arr[pos++] = arr[i];
        while (pos < arr.size()) arr[pos++] = 0;
    }
};

2)
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[count]);
                count++;
            }
        }
    }
};

3)
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        stable_partition(arr.begin(), arr.end(), [](int x) { return x != 0; });
    }
};

4)
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        for (int x : arr)
            if (x != 0) temp.push_back(x);
        for (int i = 0; i < temp.size(); i++)
            arr[i] = temp[i];
        for (int i = temp.size(); i < n; i++)
            arr[i] = 0;
    }
};
