//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;


// } Driver Code Ends
// User function Template for C

int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int mergeOverlap(Interval arr[], int n, Interval result[]) {
    if (n == 0) return 0;

    qsort(arr, n, sizeof(Interval), compare);

    result[0] = arr[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            result[index].end = result[index].end > arr[i].end ? result[index].end : arr[i].end;
        } else {
            index++;
            result[index] = arr[i];
        }
    }
    return index + 1;
}

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int n;
        scanf("%d", &n);
        Interval arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &arr[i].start, &arr[i].end);
        }
        // char ch;
        // scanf("%c", &ch);
        // getchar();
        Interval result[n];
        int mergedCount = mergeOverlap(arr, n, result);

        // Print the merged intervals
        for (int i = 0; i < mergedCount; i++) {
            printf("%d %d ", result[i].start, result[i].end);
        }
        printf("\n");
        printf("~\n");
    }

    return 0;
}
// } Driver Code Ends
