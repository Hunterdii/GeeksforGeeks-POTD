#User function Template for python3
class Solution:
    def kPangram(self, string, k):
        frequency = {}
        for c in string:
            if c.isalpha():
                frequency[c] = frequency.get(c, 0) + 1

        cnt = 0
        uniq = 0
        for key, value in frequency.items():
            if key.isalpha():
                cnt += value
                uniq += 1

        return cnt >= 26 and (26 - uniq) <= k



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        string = input()
        K = int(input())
        ob = Solution()
        a = ob.kPangram(string, K)
        if a:
            print("true")
        else:
            print("false")

# } Driver Code Ends
