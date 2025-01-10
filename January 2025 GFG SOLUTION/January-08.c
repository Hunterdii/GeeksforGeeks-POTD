//{ Driver Code Starts
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000002
int arr[MAX_SIZE];


// } Driver Code Ends
// User function Template for C
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int countTriangles(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    int count = 0;
    for (int i = n - 1; i >= 2; --i) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (arr[l] + arr[r] > arr[i]) count += (r-- - l);
            else ++l;
        }
    }
    return count;
}
//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t); // Read number of test cases

    while (t--) {
        int n = 0, input;

        // Reading input until a newline is encountered
        while (scanf("%d", &input) == 1) {
            arr[n++] = input;
            // Break when a newline is encountered
            if (getchar() == '\n')
                break;
        }

        // Print the result of the function call
        printf("%d\n~\n", countTriangles(arr, n));
    }

    return 0;
}

// } Driver Code Ends
