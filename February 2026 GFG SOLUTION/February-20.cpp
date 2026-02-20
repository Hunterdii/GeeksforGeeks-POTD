class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> s;
        for (int x : arr) s.push_back(to_string(x));
        sort(s.begin(), s.end(), [](string& a, string& b) { return a + b > b + a; });
        if (s[0] == "0") return "0";
        string res;
        for (auto& x : s) res += x;
        return res;
    }
};

2)
class Solution {
public:
    static bool myCompare(string& s1, string& s2) { 
        return (s1 + s2) > (s2 + s1); 
    }
    
    string findLargest(vector<int>& arr) {
        vector<string> numbers;
        for (int ele : arr) numbers.push_back(to_string(ele));
        sort(numbers.begin(), numbers.end(), myCompare);
        if (numbers[0] == "0") return "0";
        string res = "";
        for (string& num : numbers) res.append(num);
        return res;
    }
};

3)
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> strs;
        strs.reserve(arr.size());
        for (int x : arr) strs.push_back(to_string(x));
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0";
        string result;
        for (const string& s : strs) result += s;
        return result;
    }
};

4)
class Solution {
public:
    string findLargest(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        if (arr[0] == 0) return "0";
        string ans;
        for (int x : arr) ans += to_string(x);
        return ans;
    }
};
