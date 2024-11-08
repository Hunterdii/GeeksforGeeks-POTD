#User function Template for python3

'''

class Node():
    def __init__(self,x):
        self.data = x
        self.right = None
        self.down=None

'''
class Solution:
    def constructLinkedMatrix(self, mat):
        m = len(mat)
        n = len(mat[0])
        nodeMatrix = [[None for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                nodeMatrix[i][j] = Node(mat[i][j])

        for i in range(m):
            for j in range(n):
                if j < n - 1:
                    nodeMatrix[i][j].right = nodeMatrix[i][j + 1]  
                if i < m - 1:
                    nodeMatrix[i][j].down = nodeMatrix[i + 1][j]  

        return nodeMatrix[0][0]
#{ 
 # Driver Code Starts
class Node():

    def __init__(self, x):
        self.data = x
        self.right = None
        self.down = None


def display(head):
    Dp = head
    while Dp:
        Rp = Dp
        while Rp:
            print(Rp.data, end=" ")
            if Rp.right:
                print(Rp.right.data, end=" ")
            else:
                print("null", end=" ")
            if Rp.down:
                print(Rp.down.data, end=" ")
            else:
                print("null", end=" ")
            Rp = Rp.right
        Dp = Dp.down


if __name__ == "__main__":
    for _ in range(int(input())):
        # First row input
        a = list(map(int, input().strip().split()))
        n = len(a)

        # Input the matrix
        mat = [a]
        for i in range(1, n):
            row = list(map(int, input().strip().split()))
            mat.append(row)

        # Create a Solution object and construct the linked matrix
        obj = Solution()
        head = obj.constructLinkedMatrix(mat)
        if head is None:
            print(-1)
            continue
        display(head)
        print()

# } Driver Code Ends
