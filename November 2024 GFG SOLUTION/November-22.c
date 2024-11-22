//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

int maximumProfit(int prices[], int pricesSize) {
    int buyPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > buyPrice) { 
            maxProfit = (maxProfit > prices[i] - buyPrice) ? maxProfit : prices[i] - buyPrice;
        } else {
            buyPrice = prices[i];
        }
    }
    return maxProfit;
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
        int prices[n];
        for (int i = 0; i < n; i++) {
            prices[i] = nums[i];
        }
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Check if the array is sorted using the previously defined function
        int ans = maximumProfit(prices, n);
        printf("%d\n", ans);
        // Output 'true' if the array is sorted, 'false' otherwise

        printf("%s\n", "~");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
