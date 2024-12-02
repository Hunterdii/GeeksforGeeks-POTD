//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C
void computeLPSArray(char* pat, int m, int* lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int* search(char pat[], char txt[], int* resultSize) {
    int m = strlen(pat);
    int n = strlen(txt);

    int* lps = (int*)malloc(m * sizeof(int));
    if (!lps) {
        fprintf(stderr, "Memory allocation failed for lps\n");
        exit(1);
    }

    computeLPSArray(pat, m, lps);

    int* result = (int*)malloc(10 * sizeof(int)); 
    if (!result) {
        fprintf(stderr, "Memory allocation failed for result\n");
        free(lps);
        exit(1);
    }
    int resCapacity = 10;
    int resIndex = 0;

    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            if (resIndex >= resCapacity) {
                resCapacity *= 2;
                result = (int*)realloc(result, resCapacity * sizeof(int));
                if (!result) {
                    fprintf(stderr, "Memory reallocation failed for result\n");
                    free(lps);
                    exit(1);
                }
            }
            result[resIndex++] = i - j;
            j = lps[j - 1];
        } else if (i < n && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    *resultSize = resIndex;
    free(lps);

    return result;
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char *S = (char *)malloc(1000005 * sizeof(char));
        char *pat = (char *)malloc(1000005 * sizeof(char));
        scanf("%s\n", S);
        scanf("%s\n", pat);
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        int resultSize = 0;
        int *res = search(pat, S, &resultSize);

        if (resultSize == 0) {
            printf("[]\n");
        } else {
            for (int i = 0; i < resultSize; i++) {
                printf("%d ", res[i]);
            }
            printf("\n");
        }

        free(res);
        // printf("%s\n","~");
    }
    return 0;
}
// } Driver Code Ends
