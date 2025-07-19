class Solution {
public:
    int vowelCount(string& s) {
        int freq[26] = {}, cnt = 0, mul = 1;
        for (char c : s) if (strchr("aeiou", c)) freq[c - 'a']++;
        for (int v : {0, 4, 8, 14, 20}) if (freq[v]) mul *= freq[v], cnt++;
        return cnt ? mul * tgamma(cnt + 1) : 0;
    }
};


2)
class Solution {
public:
    int vowelCount(string& s) {
        static constexpr bool isVowel[26] = {
            1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0
        };
        int freq[5] = {0}, vowelMap[] = {0,-1,-1,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,4};
        for (char c : s) {
            if (isVowel[c - 'a']) {
                freq[vowelMap[c - 'a']]++;
            }
        }
        int cnt = 0, mul = 1;
        for (int f : freq) if (f) mul *= f, cnt++;
        for (int i = 2; i <= cnt; i++) mul *= i;
        return cnt ? mul : 0;
    }
};

3)
class Solution {
public:
    int vowelCount(string& s) {
        unordered_map<char, int> freq;
        for (char c : s) 
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                freq[c]++;
        int cnt = 0, mul = 1;
        for (auto& p : freq) {
            if (p.second > 0) {
                mul *= p.second;
                cnt++;
            }
        }
        for (int i = 2; i <= cnt; i++) mul *= i;
        return cnt ? mul : 0;
    }
};

4)
class Solution {
public:
    int vowelCount(string& s) {
        int v[5] = {0}, res = 1, cnt = 0;
        for(char c : s) {
            switch(c) {
                case 'a': v[0]++; break;
                case 'e': v[1]++; break;
                case 'i': v[2]++; break;
                case 'o': v[3]++; break;
                case 'u': v[4]++; break;
            }
        }
        for(int i = 0; i < 5; i++) if(v[i]) res *= v[i], cnt++;
        int f[] = {1,1,2,6,24,120};
        return cnt ? res * f[cnt] : 0;
    }
};


5)
class Solution {
public:
    int vowelCount(string& s) {
        int freq[5] = {0}, f[] = {1,1,2,6,24,120};
        for(char c : s) {
            if(c & 1) {
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    freq[(c == 'a') ? 0 : (c == 'e') ? 1 : (c == 'i') ? 2 : (c == 'o') ? 3 : 4]++;
            }
        }
        int res = 1, cnt = 0;
        for(int i = 0; i < 5; i++) {
            if(freq[i]) res *= freq[i], cnt++;
        }
        return cnt ? res * f[cnt] : 0;
    }
};

6)
class Solution {
public:
    int vowelCount(string& s) {
        int f[5] = {}, res = 1, cnt = 0;
        for (char c : s)
            if (c == 'a') f[0]++;
            else if (c == 'e') f[1]++;
            else if (c == 'i') f[2]++;
            else if (c == 'o') f[3]++;
            else if (c == 'u') f[4]++;
        for (int x : f) if (x) res *= x, cnt++;
        return cnt ? res * (cnt == 1 ? 1 : cnt == 2 ? 2 : cnt == 3 ? 6 : cnt == 4 ? 24 : 120) : 0;
    }
};
