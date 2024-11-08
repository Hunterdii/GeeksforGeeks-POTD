//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>

int missingNumber(int n, int arr[]);


// } Driver Code Ends
// User function Template for C
int missingNumber(int n, int arr[]) {
    int xorTotal = 0;
    int xorArray = 0;
    for (int i = 1; i <= n; i++)
        xorTotal ^= i;
    for (int i = 0; i < n - 1; i++)
        xorArray ^= arr[i];
    return xorTotal ^ xorArray;
}


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while (t > 0) {
        int n;
        scanf("%d", &n);

        int arr[n - 1];
        for (int i = 0; i < n - 1; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%d\n", missingNumber(n, arr));
        t--;
    }

    return 0;
}
// } Driver Code Ends
