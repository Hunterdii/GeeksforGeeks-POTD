class Solution:
    def countValid(self, n, arr):
        allowed = [False] * 10
        for d in arr:
            allowed[d] = True
        
        forbidden = sum(1 for i in range(10) if not allowed[i])
        non_zero_forbidden = sum(1 for i in range(1, 10) if not allowed[i])
        
        total = 9 * (10 ** (n - 1))
        invalid = non_zero_forbidden * (forbidden ** (n - 1)) if n > 1 else non_zero_forbidden
        
        return total - invalid
