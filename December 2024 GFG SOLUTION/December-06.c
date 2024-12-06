//{ Driver Code Starts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C
// Function to find the h-index
int hIndex(int citations[], int citationsSize) {
    int buckets[citationsSize + 1];
    memset(buckets, 0, sizeof(buckets));

    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= citationsSize)
            buckets[citationsSize]++;
        else
            buckets[citations[i]]++;
    }

    int cumulative = 0;
    for (int i = citationsSize; i >= 0; i--) {
        cumulative += buckets[i];
        if (cumulative >= i)
            return i;
    }
    return 0;
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
        int ans = hIndex(arr, n);
        printf("%d\n", ans);

        // printf("%s\n", "~");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
