class Solution {
  public:
    int sumSubstrings(string &s) {
        long long res=0,f=0;
        for(int i=0;i<s.size();++i){
            f=f*10+(s[i]-'0')*(i+1);
            res+=f;
        }
        return (int)res;
    }
};

2)
class Solution {
  public:
    int sumSubstrings(string &s) {
        long long res=0;
        for(int i=0;i<s.size();++i){
            long long num=0, p=1;
            for(int j=i;j>=0;--j){
                num += (s[j]-'0') * p;
                p *= 10;
                res += num;
            }
        }
        return (int)res;
    }
};


3)
class Solution {
  public:
    int sumSubstrings(string &s) {
        long long res=0;
        for(int i=0;i<s.size();++i)
            for(int j=i;j<s.size();++j)
                res += stoll(s.substr(i,j-i+1));
        return (int)res;
    }
};
