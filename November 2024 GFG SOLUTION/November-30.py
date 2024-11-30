#User function Template for python3


class Solution:
    def areAnagrams(self, s1, s2):
        if len(s1) != len(s2):
            return False

        counts = [0] * 26
        for i in range(len(s1)):
            counts[ord(s1[i]) - ord('a')] += 1
            counts[ord(s2[i]) - ord('a')] -= 1

        for count in counts:
            if count != 0:
                return False

        return True



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        a = input().strip()
        b = input().strip()
        if (Solution().areAnagrams(a, b)):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends
