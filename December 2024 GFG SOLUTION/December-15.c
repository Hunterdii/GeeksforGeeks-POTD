//{ Driver Code Starts
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C
//  Function to find the peak element
int peakElement(int *arr, int n) {
    int lo = 0, hi = n - 1;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] > arr[mid + 1]) {
            hi = mid;  
        } else {
            lo = mid + 1;  
        }
    }

    return lo;  
}


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // Consume the newline after the integer input

    while (t--) {
        int a[1000];
        char input[10000];
        fgets(input, sizeof(input), stdin);

        int n = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            a[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        int idx = peakElement(a, n);
        bool f = false;

        if (idx < 0 || idx >= n)
            printf("false\n");
        else {
            if (n == 1 && idx == 0)
                f = true;
            else if (idx == 0 && a[0] > a[1])
                f = true;
            else if (idx == n - 1 && a[n - 1] > a[n - 2])
                f = true;
            else if (a[idx] > a[idx + 1] && a[idx] > a[idx - 1])
                f = true;

            if (f)
                printf("true\n");
            else
                printf("false\n");
        }

        printf("~\n");
    }

    return 0;
}

// } Driver Code Ends
