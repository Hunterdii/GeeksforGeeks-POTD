//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    int circularSubarraySum(vector<int>& a) {
        int n = a.size();
        int max_kadane = kadane(a);
        int total_sum = 0, min_kadane = 0;
        bool all_negative = true;
        for (int num : a) {
            total_sum += num;
            if (num > 0) all_negative = false;
        }
        if (all_negative) return max_kadane;
        min_kadane = kadaneNegative(a);
        int max_wrap = total_sum - min_kadane;
        return max(max_kadane, max_wrap);
    }
private:
    int kadane(vector<int>& a) {
        int max_ending_here = 0, max_so_far = INT_MIN;
        for (int num : a) {
            max_ending_here = max(num, max_ending_here + num);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }

    int kadaneNegative(vector<int>& a) {
        int min_ending_here = 0, min_so_far = INT_MAX;
        for (int num : a) {
            min_ending_here = min(num, min_ending_here + num);
            min_so_far = min(min_so_far, min_ending_here);
        }
        return min_so_far;
    }
};

class Solution {
public:
    int circularSubarraySum(vector<int>& a) {
        int total_sum = 0, max_sum = INT_MIN, min_sum = INT_MAX;
        int curr_max = 0, curr_min = 0;
        bool all_negative = true;
        for (int num : a) {
            total_sum += num;
            curr_max = max(num, curr_max + num);
            max_sum = max(max_sum, curr_max);
            curr_min = min(num, curr_min + num);
            min_sum = min(min_sum, curr_min);
            if (num > 0) all_negative = false;
        }
        if (all_negative) return max_sum;
        return max(max_sum, total_sum - min_sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
