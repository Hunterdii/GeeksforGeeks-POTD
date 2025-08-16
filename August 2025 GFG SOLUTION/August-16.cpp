class Solution {
public:
    string findLargest(vector<int>& arr) {
        auto cmp = [](string a, string b) { return a + b < b + a; };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (int x : arr) pq.push(to_string(x));
        string res = "";
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res[0] == '0' ? "0" : res;
    }
};

2)
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> s;
        for (int x : arr) s.push_back(to_string(x));
        sort(s.begin(), s.end(), [](const string& x, const string& y) { 
            return x + y > y + x; 
        });
        if (s[0] == "0") return "0";
        string result;
        for (const string& str : s) result += str;
        return result;
    }
};

3)
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> nums;
        nums.reserve(arr.size());
        for (int val : arr) nums.emplace_back(to_string(val));
        sort(nums.begin(), nums.end(), [](const string& x, const string& y) {
            return x + y > y + x;
        });
        if (nums[0] == "0") return "0";
        string result;
        for (const string& num : nums) result += num;
        return result;
    }
};


4)
class Solution {
public:
    string findLargest(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            long long ab = stoll(to_string(a) + to_string(b));
            long long ba = stoll(to_string(b) + to_string(a));
            return ab > ba;
        });
        if (arr[0] == 0) return "0";
        string res;
        for (int x : arr) res += to_string(x);
        return res;
    }
};


5)
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> nums;
        nums.reserve(arr.size());
        int totalLen = 0;
        
        for(int x : arr) {
            string s = to_string(x);
            nums.push_back(s);
            totalLen += s.length();
        }
        
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        if(nums[0] == "0") return "0";
        
        string result;
        result.reserve(totalLen);
        for(const string& num : nums) result += num;
        
        return result;
    }
};



6)
class Solution {
public:
    struct Compare {
        bool operator()(const string& x, const string& y) {
            return x + y > y + x;
        }
    };
    
    string findLargest(vector<int>& arr) {
        vector<string> nums;
        transform(arr.begin(), arr.end(), back_inserter(nums), [](int x) { return to_string(x); });
        sort(nums.begin(), nums.end(), Compare());
        if (nums[0] == "0") return "0";
        return accumulate(nums.begin(), nums.end(), string{});
    }
};
