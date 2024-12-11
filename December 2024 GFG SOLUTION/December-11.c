//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C
void mergeArrays(int* a, int n, int* b, int m) {
    int gap = n + m;
    int nextGap(int gap) {
        return (gap <= 1) ? 0 : (gap / 2) + (gap % 2);
    }

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        int i, j;

        for (i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) {
                int temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
            }
        }
        for (j = (gap > n ? gap - n : 0); i < n && j < m; i++, j++) {
            if (a[i] > b[j]) {
                int temp = a[i];
                a[i] = b[j];
                b[j] = temp;
            }
        }
        for (j = 0; j + gap < m; j++) {
            if (b[j] > b[j + gap]) {
                int temp = b[j];
                b[j] = b[j + gap];
                b[j + gap] = temp;
            }
        }
    }
}

//{ Driver Code Starts.

// Function to read a line of integers and store them in an array
int readArray(int** arr) {
    char line[1000000];
    fgets(line, sizeof(line), stdin);

    int* temp = malloc(10000000 * sizeof(int));
    int size = 0;

    char* token = strtok(line, " ");
    while (token) {
        temp[size++] = atoi(token);
        token = strtok(NULL, " ");
    }

    *arr = realloc(temp, size * sizeof(int)); // Resize array to actual size
    return size;
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // Consume the newline after the test case count

    while (t--) {
        int *a, *b;
        int n, m;

        // Read the two arrays
        n = readArray(&a);
        m = readArray(&b);

        mergeArrays(a, n, b, m);

        // Print the merged arrays
        printArray(a, n);
        printArray(b, m);
        printf("~\n");

        // Free allocated memory
        free(a);
        free(b);
    }

    return 0;
}

// } Driver Code Ends
