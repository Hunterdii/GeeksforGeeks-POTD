class Solution {
public:
    int romanToDecimal(string s) {
        int vals[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string syms[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int res = 0, i = 0;
        for (int j = 0; j < 13; j++) {
            while (i + syms[j].length() <= s.length() && s.substr(i, syms[j].length()) == syms[j]) {
                res += vals[j];
                i += syms[j].length();
            }
        }
        return res;
    }
};

2)
class Solution {
public:
    int romanToDecimal(string s) {
        unordered_map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && m[s[i]] < m[s[i+1]]) {
                res += m[s[i+1]] - m[s[i]];
                i++;
            } else {
                res += m[s[i]];
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    int romanToDecimal(string s) {
        int vals[256] = {0};
        vals['I'] = 1; vals['V'] = 5; vals['X'] = 10; vals['L'] = 50;
        vals['C'] = 100; vals['D'] = 500; vals['M'] = 1000;
        int res = 0, maxVal = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int val = vals[s[i]];
            if (val < maxVal) res -= val;
            else {
                res += val;
                maxVal = val;
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    int getVal(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToDecimal(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = getVal(s[i]);
            int next = (i + 1 < s.length()) ? getVal(s[i+1]) : 0;
            if (curr < next) {
                res += next - curr;
                i++;
            } else {
                res += curr;
            }
        }
        return res;
    }
};
