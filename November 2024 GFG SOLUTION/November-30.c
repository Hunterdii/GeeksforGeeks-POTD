//{ Driver Code Starts
// Initial Template for C
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

bool areAnagrams(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) return false;

    int counts[26] = {0};
    for (int i = 0; i < strlen(s1); i++) {
        counts[s1[i] - 'a']++;
        counts[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) return false;
    }

    return true;
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d\n", &t);

    while (t--) {
        // Dynamically allocate memory for strings
        char *c = (char *)malloc(100005 * sizeof(char));
        char *d = (char *)malloc(100005 * sizeof(char));

        // Input the strings
        scanf("%s\n", c);
        scanf("%s\n", d);
        // Check if they are anagrams and print the result
        if (areAnagrams(c, d))
            printf("true\n");
        else
            printf("false\n");
        printf("%s\n", "~");

        // Free the allocated memory
        free(c);
        free(d);
    }

    return 0;
}

// } Driver Code Ends
