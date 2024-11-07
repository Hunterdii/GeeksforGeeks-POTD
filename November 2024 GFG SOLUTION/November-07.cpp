//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }
        
        if (total_sum % 3 != 0) {
            return {-1, -1};
        }
        
        int target_sum = total_sum / 3;
        int current_sum = 0;
        int first_index = -1, second_index = -1;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            current_sum += arr[i];
            
            if (current_sum == target_sum && first_index == -1) {
                first_index = i;
            }
            
            if (current_sum == 2 * target_sum && first_index != -1) {
                second_index = i;
                break;
            }
        }
        
        if (first_index != -1 && second_index != -1) {
            int last_part_sum = 0;
            for (int i = second_index + 1; i < n; i++) {
                last_part_sum += arr[i];
            }
            if (last_part_sum == target_sum) {
                return {first_index, second_index};
            }
        }
        
        return {-1, -1};
    }
};
//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
