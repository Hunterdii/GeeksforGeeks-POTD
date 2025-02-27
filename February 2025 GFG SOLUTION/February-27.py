class Solution:
    def __init__(self): self.s, self.m = [], []

    def push(self, x): self.s.append(x); self.m.append(x if not self.m else min(x, self.m[-1]))
    def pop(self): 
        if self.s: self.s.pop(); self.m.pop()
    def peek(self): return -1 if not self.s else self.s[-1]
    def getMin(self): return -1 if not self.m else self.m[-1]

2)
class Solution:
    def __init__(self):
        self.s, self.m = [], []

    def push(self, x):
        self.s.append(x)
        self.m.append(x if not self.m else min(x, self.m[-1]))

    def pop(self):
        if self.s: self.s.pop(), self.m.pop()

    def peek(self):
        return -1 if not self.s else self.s[-1]

    def getMin(self):
        return -1 if not self.m else self.m[-1]

#{ 
 # Driver Code Starts
# Driver Code
if __name__ == '__main__':
    t = int(input())  # Number of test cases

    for _ in range(t):
        q = int(input())  # Number of queries
        stk = Solution()  # Initialize stack
        results = []

        for _ in range(q):
            query = list(map(int, input().split()))

            if query[0] == 1:
                stk.push(query[1])  # Push operation
            elif query[0] == 2:
                stk.pop()  # Pop operation (no return value)
            elif query[0] == 3:
                results.append(str(stk.peek()))  # Peek operation
            elif query[0] == 4:
                results.append(str(stk.getMin()))  # GetMin operation

        print(" ".join(results))  # Print all results in one line
        print("~")

# } Driver Code Ends
