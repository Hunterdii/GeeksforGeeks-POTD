class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<int> s;
        for (int& x : arr) s.insert(x * x);
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                if (s.count(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
};

2)
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int freq[1001] = {0};
        for(int x: arr) freq[x]++;
        vector<int> u;
        for(int i=1;i<=1000;++i) if(freq[i]) u.push_back(i);
        int m = u.size();
        for(int i=0;i<m;++i) for(int j=i;j<m;++j) {
            int a=u[i], b=u[j], c2=a*a + b*b;
            int c = int(round(sqrt(c2)));
            if(c>1000 || c*c!=c2 || freq[c]==0) continue;
            if(a==b && b==c && freq[a]>=3) return true;
            if(a==b && freq[a]>=2 && freq[c]>=1 && c!=a) return true;
            if(a==c && freq[a]>=2 && freq[b]>=1 && b!=a) return true;
            if(b==c && freq[b]>=2 && freq[a]>=1 && a!=b) return true;
            if(a!=b && b!=c && a!=c) return true;
        }
        return false;
    }
};
