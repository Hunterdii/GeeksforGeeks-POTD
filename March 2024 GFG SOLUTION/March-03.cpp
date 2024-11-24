class Solution {
public:
 static bool comp(string a, string b){
     return a + b > b + a;
 }
 
 string printLargest(int n, vector<string> &arr) {
     sort(arr.begin(), arr.end(), comp);
     
     string ans;
     for(string i : arr)
         ans += i;
     
     return ans;
 }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
