//{ Driver Code Starts
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// } Driver Code Ends
// User function Template for C

int kthElement(int *a, int n, int *b, int m, int k) {
    if (n > m) return kthElement(b, m, a, n, k);

    int low = k > m ? k - m : 0, high = k < n ? k : n;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 > 0) ? a[cut1 - 1] : INT_MIN;
        int l2 = (cut2 > 0) ? b[cut2 - 1] : INT_MIN;
        int r1 = (cut1 < n) ? a[cut1] : INT_MAX;
        int r2 = (cut2 < m) ? b[cut2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return l1 > l2 ? l1 : l2;
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return -1;
}


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);

        // Dynamically allocate memory for arrays
        int *a = (int *)malloc(1000000 * sizeof(int));
        int *b = (int *)malloc(1000000 * sizeof(int));
        if (!a || !b) {
            printf("Memory allocation failed\n");
            return 1;
        }

        int n = 0, m = 0;

        // Read first array
        while (scanf("%d", &a[n]) == 1) {
            n++;
            if (getchar() == '\n')
                break;
        }

        // Read second array
        while (scanf("%d", &b[m]) == 1) {
            m++;
            if (getchar() == '\n')
                break;
        }

        printf("%d\n", kthElement(a, n, b, m, k));
        printf("%s\n", "~");

        // Free allocated memory
        free(a);
        free(b);
    }

    return 0;
}

// } Driver Code Ends
