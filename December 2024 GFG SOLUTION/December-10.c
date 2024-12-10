//{ Driver Code Starts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for an interval
typedef struct Interval {
    int start;
    int end;
} Interval;


// } Driver Code Ends
// User function Template for C

/*
// Define a struct for an interval
typedef struct Interval {
    int start;
    int end;
} Interval;
*/

int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return (intervalA->start - intervalB->start);
}
int minRemoval(Interval *intervals, int intervalsSize) {
    qsort(intervals, intervalsSize, sizeof(Interval), compare);
    int count = 0, prevEnd = intervals[0].end;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i].start < prevEnd) {
            count++;
            prevEnd = (prevEnd < intervals[i].end) ? prevEnd : intervals[i].end;
        } else {
            prevEnd = intervals[i].end;
        }
    }
    return count;
}

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int N;
        scanf("%d", &N);
        Interval* intervals = (Interval*)malloc(N * sizeof(Interval));

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &intervals[i].start, &intervals[i].end);
        }

        int result = minRemoval(intervals, N);
        printf("%d\n", result);

        free(intervals);

        printf("~\n");
    }
    return 0;
}

// } Driver Code Ends
