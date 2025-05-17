class Solution:
    def sortArray(self, arr, A, B, C):
        n, l, r, i = len(arr), 0, len(arr) - 1, len(arr) - 1 if A >= 0 else 0
        f = lambda x: A * x * x + B * x + C
        res = [0] * n
        while l <= r:
            lv, rv = f(arr[l]), f(arr[r])
            if A >= 0:
                res[i] = lv if lv > rv else rv
                i -= 1
                l += lv > rv
                r -= lv <= rv
            else:
                res[i] = lv if lv < rv else rv
                i += 1
                l += lv < rv
                r -= lv >= rv
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        a = int(input())
        b = int(input())
        c = int(input())

        ob = Solution()
        ans = ob.sortArray(arr, a, b, c)
        print(' '.join(map(str, ans)))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
