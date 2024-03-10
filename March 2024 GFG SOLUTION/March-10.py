#User function Template for python3
class Solution:
    def removeDuplicates(self, str):
        # Initialize a set to keep track of seen characters
        seen = set()
        # Initialize an empty string to store the result
        result = ''
        
        # Iterate through each character in the string
        for char in str:
            # If the character has not been seen before, add it to the result and the set
            if char not in seen:
                result += char
                seen.add(char)
        
        return result

#{ 
# Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        str = input().strip()
        ob = Solution()
        ans = ob.removeDuplicates(str)
        print(ans)
        tc -= 1

# } Driver Code Ends
