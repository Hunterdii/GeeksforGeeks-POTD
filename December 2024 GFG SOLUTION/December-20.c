//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>


// } Driver Code Ends
// User function Template for C
// Print the answer in one line with each element space separated.
// Don't print any new lines after printing the answer line
// r -> number of rows
// c -> number of columns
void spirallyTraverse(int** mat, int r, int c) {
    int top = 0, left = 0, bottom = r - 1, right = c - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; printf("%d ", mat[top][i++]));
        top++;
        for (int i = top; i <= bottom; printf("%d ", mat[i++][right]));
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; printf("%d ", mat[bottom][i--]));
        bottom--;
        if (left <= right)
            for (int i = bottom; i >= top; printf("%d ", mat[i--][left]));
        left++;
    }
    printf("\n");
}
//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t); // Read number of test cases

    while (t--) {
        int r, c;
        scanf("%d", &r); // Read matrix dimensions
        scanf("%d", &c);

        // Dynamically allocate memory for the matrix
        int** matrix = (int**)malloc(r * sizeof(int*));
        for (int i = 0; i < r; i++) {
            matrix[i] = (int*)malloc(c * sizeof(int));
        }

        // Read matrix elements
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        // Perform spiral traversal
        spirallyTraverse(matrix, r, c);
        printf("%s\n", "~");

        // Free dynamically allocated memory
        for (int i = 0; i < r; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}

// } Driver Code Ends
