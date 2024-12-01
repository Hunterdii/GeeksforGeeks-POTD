//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

char nonRepeatingChar(char s[]) {
    int freq[26] = {0};  
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char *s = (char *)malloc(100005 * sizeof(char));

        // Input the strings
        scanf("%s\n", s);
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Add the binary strings
        char result = nonRepeatingChar(s);
        if (result == '$') {
            printf("%d\n", -1);
        } else {
            printf("%c\n", result);
        }
        // Display the result

        printf("%s\n", "~");

        // Free allocated memory
        free(s);
    }

    return 0;
}
// } Driver Code Ends
