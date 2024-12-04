//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// } Driver Code Ends
// User function Template for C

int areRotations(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return 0;
    char* temp = (char*)malloc(2 * strlen(s1) + 1);
    strcpy(temp, s1);
    strcat(temp, s1);
    int result = (strstr(temp, s2) != NULL);

    free(temp); 
    return result;
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        char *s1 = (char *)malloc(100005 * sizeof(char));
        char *s2 = (char *)malloc(100005 * sizeof(char));

        // Input the strings
        scanf("%s\n", s1);
        scanf("%s\n", s2);
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        // Add the binary strings
        int result = areRotations(s1, s2);
        if (result) {
            printf("%s\n", "true");
        } else {
            printf("%s\n", "false");
        }

        // Display the result

        printf("%s\n", "~");

        // Free allocated memory
        free(s1);
        free(s2);
    }

    return 0;
}
// } Driver Code Ends
