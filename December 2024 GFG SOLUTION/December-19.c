//{ Driver Code Starts
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// } Driver Code Ends
// User function Template for C

int kthMissing(int* arr, int n, int k) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] - (mid + 1) < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo + k;
}


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        // Dynamically allocate memory for arrays
        int *a = (int *)malloc(1000000 * sizeof(int));
        int n = 0;

        // Read first array
        while (scanf("%d", &a[n]) == 1) {
            n++;
            if (getchar() == '\n')
                break;
        }
        int k;
        scanf("%d\n", &k);

        printf("%d\n", kthMissing(a, n, k));

        // Free allocated memory
        free(a);
    }

    return 0;
}

// } Driver Code Ends
