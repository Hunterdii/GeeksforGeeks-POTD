class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int orVal = 0;
        for (int x : arr) orVal |= x;
        return orVal << (arr.size() - 1);
    }
};

2)
class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        return accumulate(arr.begin(), arr.end(), 0, bit_or<>()) << (arr.size() - 1);
    }
};

3)
class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int result = 0;
        for (int i = 0; i < arr.size(); i++) result |= arr[i];
        return result * (1 << (arr.size() - 1));
    }
};
