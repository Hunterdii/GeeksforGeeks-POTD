Interval* insertInterval(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize) {
    Interval* result = (Interval*)malloc((intervalsSize + 1) * sizeof(Interval));
    int i = 0, idx = 0;
    
    while (i < intervalsSize && intervals[i].end < newInterval.start)
        result[idx++] = intervals[i++];
    
    while (i < intervalsSize && intervals[i].start <= newInterval.end) {
        newInterval.start = (intervals[i].start < newInterval.start) ? intervals[i].start : newInterval.start;
        newInterval.end = (intervals[i].end > newInterval.end) ? intervals[i].end : newInterval.end;
        i++;
    }
    result[idx++] = newInterval;
    
    while (i < intervalsSize) result[idx++] = intervals[i++];
    
    *returnSize = idx;
    return result;
}
