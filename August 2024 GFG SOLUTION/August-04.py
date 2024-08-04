1)
class Solution:
    def maximumMeetings(self, n, start, end):
        meetings = list(zip(start, end))
        meetings.sort(key=lambda x: x[1])

        count = 0
        last_end_time = 0
        for s, e in meetings:
            if s > last_end_time:
                count += 1
                last_end_time = e

        return count

2)
class Solution:
    def maximumMeetings(self, n, start, end):
        meetings = [(start[i], end[i]) for i in range(n)]
        meetings.sort(key=lambda x: (x[1], x[0]))

        last_end_time = -1
        count = 0
            for meeting in meetings:
            if meeting[0] > last_end_time:
                count += 1
                last_end_time = meeting[1]

        return count

3)
class Solution:
    def maximumMeetings(self, n, start, end):
        meetings = [(start[i], end[i]) for i in range(n)]
        meetings.sort(key=lambda x: x[1])
        count = 0
        last_end_time = -1
        for meeting in meetings:
            if meeting[0] > last_end_time:
                count += 1
                last_end_time = meeting[1]

        return count




#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        start = list(map(int,input().strip().split()))
        end = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.maximumMeetings(n,start,end))
# } Driver Code Ends
