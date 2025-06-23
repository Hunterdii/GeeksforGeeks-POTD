class Solution {
public:
    string addString(string &s1, string &s2) {
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += (s1[i--] - '0');
            if (j >= 0) sum += (s2[j--] - '0');
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        while (!res.empty() && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
    string minSum(vector<int> &arr) {
        vector<int> count(10, 0);
        for (int num : arr) count[num]++;
        string s1 = "", s2 = "";
        bool firstNum = true;
        for (int digit = 0; digit < 10; digit++) {
            while (count[digit]--) {
                if (firstNum) {
                    if (!(s1.empty() && digit == 0)) s1.push_back(digit + '0');
                    firstNum = false;
                } else {
                    if (!(s2.empty() && digit == 0)) s2.push_back(digit + '0');
                    firstNum = true;
                }
            }
        }
        if (s1.empty()) s1 = "0";
        if (s2.empty()) s2 = "0";
        return addString(s1, s2);
    }
};


2)
class Solution {
public:
    string addString(string &a, string &b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string r;
        while (i>=0||j>=0||c) {
            if (i>=0) c += a[i--]-'0';
            if (j>=0) c += b[j--]-'0';
            r.push_back(c%10+'0');
            c /= 10;
        }
        while (r.size()>1 && r.back()=='0') r.pop_back();
        reverse(r.begin(), r.end());
        return r;
    }
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string s1, s2;
        for (int i = 0; i < arr.size(); i++) {
            char d = char(arr[i] + '0');
            if (i % 2 == 0) { if (!s1.empty() || d!='0') s1 += d; }
            else          { if (!s2.empty() || d!='0') s2 += d; }
        }
        if (s1.empty()) s1="0";
        if (s2.empty()) s2="0";
        return addString(s1, s2);
    }
};


3)
class Solution {
public:
    string addString(string &a, string &b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string r;
        r.reserve(max(a.size(), b.size()) + 1);
        while (i>=0||j>=0||c) {
            if (i>=0) c += a[i--]-'0';
            if (j>=0) c += b[j--]-'0';
            r.push_back(c%10+'0');
            c /= 10;
        }
        while (r.size()>1 && r.back()=='0') r.pop_back();
        reverse(r.begin(), r.end());
        return r;
    }
    string minSum(vector<int> &arr) {
        int count[10] = {0};
        for (int x : arr) count[x]++;
        string s1, s2;
        s1.reserve(arr.size()/2 + 1);
        s2.reserve(arr.size()/2 + 1);
        bool first = true;
        for (int d = 0; d < 10; d++) {
            while (count[d]--) {
                if (first) {
                    if (!s1.empty() || d) s1 += char('0'+d);
                    first = false;
                } else {
                    if (!s2.empty() || d) s2 += char('0'+d);
                    first = true;
                }
            }
        }
        if (s1.empty()) s1 = "0";
        if (s2.empty()) s2 = "0";
        return addString(s1, s2);
    }
};


4)
class Solution {
public:
    string addString(string &a, string &b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string r;
        while (i>=0||j>=0||c) {
            if (i>=0) c += a[i--]-'0';
            if (j>=0) c += b[j--]-'0';
            r.push_back(c%10+'0');
            c /= 10;
        }
        while (r.size()>1 && r.back()=='0') r.pop_back();
        reverse(r.begin(), r.end());
        return r;
    }
    string minSum(vector<int> &arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        string s1, s2;
        bool turn = true;
        while (!pq.empty()) {
            char d = char(pq.top()+'0');
            pq.pop();
            if (turn) {
                if (!s1.empty() || d!='0') s1 += d;
            } else {
                if (!s2.empty() || d!='0') s2 += d;
            }
            turn = !turn;
        }
        if (s1.empty()) s1="0";
        if (s2.empty()) s2="0";
        return addString(s1, s2);
    }
};
