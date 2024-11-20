//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

int* findMajority(int arr[], int n, int* resultSize) {
    int num1 = -1, num2 = -1, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1) {
            c1++;
        } else if (arr[i] == num2) {
            c2++;
        } else if (c1 == 0) {
            num1 = arr[i];
            c1 = 1;
        } else if (c2 == 0) {
            num2 = arr[i];
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }
    c1 = c2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1) c1++;
        else if (arr[i] == num2) c2++;
    }
    int* result = (int*)malloc(2 * sizeof(int));
    *resultSize = 0;
    if (c1 > n / 3) result[(*resultSize)++] = num1;
    if (c2 > n / 3) result[(*resultSize)++] = num2;
    if (*resultSize == 2 && result[0] > result[1]) {
        int temp = result[1];
        result[1] = result[0];
        result[0] = temp;
    }

    return result;
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // Consume the newline character after the number of test cases

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

        int resultSize;
        int *result = findMajority(brr, n, &resultSize);

        if (resultSize == 0) {
            printf("[]\n");
            printf("%s\n", "~");
        } else {
            // Sort result if two elements exist
            // if (resultSize == 2 && result[0] > result[1]) {
            //     int temp = result[1];
            //     result[1] = result[0];
            //     result[0] = temp;
            // }
            for (int i = 0; i < resultSize; i++) {
                printf("%d ", result[i]);
            }
            printf("\n");
            printf("%s\n", "~");
        }

        free(nums);
        free(result);
    }

    return 0;
}

// } Driver Code Ends
