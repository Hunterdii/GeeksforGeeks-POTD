//{ Driver Code Starts
// Initial Template for C
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

// Function to find the maximum circular subarray sum.
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int circularSubarraySum(int arr[], int n) {
    int total_sum = 0, max_sum = INT_MIN, min_sum = INT_MAX;
    int curr_max = 0, curr_min = 0;
    int all_negative = 1;

    for (int i = 0; i < n; i++) {
        total_sum += arr[i];

        curr_max = max(arr[i], curr_max + arr[i]);
        max_sum = max(max_sum, curr_max);

        curr_min = min(arr[i], curr_min + arr[i]);
        min_sum = min(min_sum, curr_min);

        if (arr[i] > 0) all_negative = 0;
    }

    if (all_negative) return max_sum;

    return max(max_sum, total_sum - min_sum);
}



//{ Driver Code Starts.

int main() {
    char ts[1001];
    fgets(ts, sizeof(ts), stdin);
    int t = atoi(ts);
    while (t--) {
        char *line = NULL;
        size_t len = 0;
        long read = getline(&line, &len, stdin);

        int *nums = (int *)malloc(1000000 * sizeof(int));
        int n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            nums[n++] = atoi(token);
            token = strtok(NULL, " "); // Get the next token
        }
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Check if the array is sorted using the previously defined function
        int ans = circularSubarraySum(arr, n);
        printf("%d\n", ans);

        printf("%s\n", "~");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
