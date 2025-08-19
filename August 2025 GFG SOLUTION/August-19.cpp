class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        vector<int> suff(n);
        suff[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) suff[i] = min(arr[i], suff[i+1]);
        for(int i = 0; i < n; ++i) {
            int lo = i+1, hi = n-1, res = -1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(suff[mid] < arr[i]) {
                    res = mid;
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};
