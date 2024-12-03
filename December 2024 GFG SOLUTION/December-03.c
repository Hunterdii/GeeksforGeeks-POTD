//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C
void computeLPSArray(char* pat, int M, int* lps) {
    int length = 0; 
    lps[0] = 0; 
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int minChar(char str[]) {
    int n = strlen(str);
    char revStr[n + 1];
    for (int i = 0; i < n; i++) {
        revStr[i] = str[n - i - 1];
    }
    revStr[n] = '\0';

    char combined[2 * n + 2];
    snprintf(combined, sizeof(combined), "%s$%s", str, revStr);

    int lps[2 * n + 2];
    computeLPSArray(combined, strlen(combined), lps);

    return n - lps[strlen(combined) - 1];
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char *s = (char *)malloc(1000005 * sizeof(char));

        // Input the strings
        scanf("%s\n", s);
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Add the binary strings
        int result = minChar(s);
        printf("%d\n", result);

        // Display the result

        printf("%s\n", "~");

        // Free allocated memory
        free(s);
    }

    return 0;
}
// } Driver Code Ends
