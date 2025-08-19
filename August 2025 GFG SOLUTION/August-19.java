class Solution {
    public ArrayList<Integer> farMin(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int[] suff = new int[n];
        suff[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) suff[i] = Math.min(arr[i], suff[i+1]);
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
            ans.add(res);
        }
        return ans;
    }
}
