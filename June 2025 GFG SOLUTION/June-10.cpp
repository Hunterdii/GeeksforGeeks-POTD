class Solution{
public:
    int countStrings(string &s){
        vector<int> m(26);
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            ans += i - m[s[i] - 'a'];
            ++m[s[i] - 'a'];
        }
        for(int x : m) if(x > 1){ ++ans; break; }
        return ans;
    }
};

2)
class Solution {
  public:
    int countStrings(string &s) {
        int map[26] = {}, ans = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            ans += i - map[s[i] - 'a'];
            map[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
            if (map[i] > 1) return ans + 1;
        return ans;
    }
};

3)
class Solution{
public:
    int countStrings(string &s){
        int n = s.size(), a[26] = {}, ans = 0;
        for(int i = 0; i < n; ++i){
            ans += i - a[s[i] - 'a'];
            ++a[s[i] - 'a'];
        }
        return ans + (any_of(a, a+26, [](int x){ return x > 1; }) ? 1 : 0);
    }
};
