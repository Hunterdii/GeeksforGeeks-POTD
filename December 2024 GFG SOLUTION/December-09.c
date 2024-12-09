//{ Driver Code Starts

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for intervals
typedef struct {
    int start;
    int end;
} Interval;


// } Driver Code Ends
// User function Template for C

// Return the intervals and change the value of returnSize with the returned intervals
// size

Interval* insertInterval(Interval* intervals, int intervalsSize, Interval newInterval,
                         int* returnSize) {
    Interval* result = (Interval*)malloc((intervalsSize + 1) * sizeof(Interval));
    int idx = 0;

    for (int i = 0; i < intervalsSize; i++) {
        if (intervals[i].end < newInterval.start) {
            result[idx++] = intervals[i];
        } 
        else if (intervals[i].start <= newInterval.end) {
            newInterval.start = (newInterval.start < intervals[i].start) ? newInterval.start : intervals[i].start;
            newInterval.end = (newInterval.end > intervals[i].end) ? newInterval.end : intervals[i].end;
        } 
        else {
            result[idx++] = newInterval;
            newInterval = intervals[i];
        }
    }
    result[idx++] = newInterval;

    *returnSize = idx;
    return result;
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

        Interval newInterval;
        scanf("%d %d", &newInterval.start, &newInterval.end);

        int returnSize;
        Interval* ans = insertInterval(intervals, N, newInterval, &returnSize);

        printf("[");
        for (int i = 0; i < returnSize; i++) {
            printf("[%d,%d]", ans[i].start, ans[i].end);
            if (i != returnSize - 1) {
                printf(",");
            }
        }
        printf("]\n");

        free(intervals);
        free(ans);

        printf("~\n");
    }
    return 0;
}

// } Driver Code Ends
