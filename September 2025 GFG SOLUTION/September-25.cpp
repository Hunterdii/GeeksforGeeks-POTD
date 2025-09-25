class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int x = i + 1; x; x /= 2) s = char('0' + x % 2) + s;
            res[i] = s;
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        queue<string> q;
        q.push("1");
        for(int i = 0; i < n; i++) {
            string curr = q.front(); q.pop();
            res.push_back(curr);
            q.push(curr + "0");
            q.push(curr + "1");
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            string bin = "";
            int num = i;
            while(num) {
                bin = (num & 1 ? "1" : "0") + bin;
                num >>= 1;
            }
            res.push_back(bin);
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            res.push_back(bitset<32>(i).to_string().substr(
                bitset<32>(i).to_string().find('1')));
        }
        return res;
    }
};
