//{ Driver Code Starts
// Initial Template for C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

// Function to find the next permutation
void nextPermutation(int arr[], int n) {
    int i = n - 2, j = n - 1;

    while (i >= 0 && arr[i] >= arr[i + 1])
        i--;

    if (i >= 0) {

        while (arr[j] <= arr[i])
            j--;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int start = i + 1, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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
        int brr[n];
        for (int i = 0; i < n; i++) {
            brr[i] = nums[i];
        }
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        //  Check if the array is sorted using the previously defined function
        nextPermutation(brr, n);
        // Output 'true' if the array is sorted, 'false' otherwise
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                printf("%d\n", brr[i]);
                continue;
            }
            printf("%d ", brr[i]);
        }
        printf("%s\n", "~");
        free(nums); // Free dynamically allocated memory for the nums array
        free(line); // Free dynamically allocated memory for the input line
    }

    return 0; // Return 0 to indicate successful execution
}
// } Driver Code Ends
