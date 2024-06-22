import re

class Solution:
    def ExtractNumber(self, sentence):
        numbers = re.findall(r'\d+', sentence)
        
        answer = -1
        max_value = -1
        
        for number in numbers:
            num_value = int(number)
            if '9' not in number and num_value > max_value:
                answer = number
                max_value = num_value
        
        return answer



#{ 
 # Driver Code Starts
t = int(input())
for _ in range(t):
    S = input()
    ob = Solution()
    ans = ob.ExtractNumber(S)
    print(ans)

# } Driver Code Ends
