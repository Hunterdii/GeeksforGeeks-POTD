//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>


// } Driver Code Ends
// User function Template for C

void rotate(int n, int mat[][n]) {
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = temp;
        }
    }
}


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int a[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        }
        rotate(n, a);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }

        printf("~%s", "\n");
    }
    return 0;
}

// } Driver Code Ends
