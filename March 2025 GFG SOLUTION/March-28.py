
class Solution:
    def activitySelection(self, start, finish):
        ans, finishtime = 0, -1
        for s, f in sorted(zip(start, finish), key=lambda x: x[1]):
            if s > finishtime: finishtime = f; ans += 1
        return ans

#{ 
 # Driver Code Starts
def main():
    t = int(input().strip())  # Number of test cases

    for _ in range(t):
        # Read the start times
        start = list(map(int, input().strip().split()))

        # Read the finish times
        finish = list(map(int, input().strip().split()))

        # Create solution object and call activitySelection
        obj = Solution()
        print(obj.activitySelection(start, finish))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
