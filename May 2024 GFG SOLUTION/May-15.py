#User function Template for python3

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def unite(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            elif self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1


class Solution:
    def accountsMerge(self, accounts):
        emailToIndex = {}
        emailToName = {}
        n = len(accounts)
        uf = UnionFind(n)

        # Map emails to indices and names
        for i in range(n):
            for j in range(1, len(accounts[i])):
                email = accounts[i][j]
                emailToIndex[email] = i
                emailToName[email] = accounts[i][0]

        # Union emails with the same owner
        for acc in accounts:
            root = emailToIndex[acc[1]]
            for j in range(2, len(acc)):
                uf.unite(root, emailToIndex[acc[j]])

        # Group emails by owner
        mergedAccounts = {}
        for acc in accounts:
            root = uf.find(emailToIndex[acc[1]])
            mergedAccounts.setdefault(root, set()).update(acc[1:])

        # Build the result
        result = []
        for root, emails in mergedAccounts.items():
            account = [emailToName[list(emails)[0]]]
            account.extend(sorted(emails))
            result.append(account)

        return result



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input ())
    for _ in range (t):
        n = int(input())
        accounts = []
        for i in range(n):
            cntEmails = int(input())
            nameEmails = input().split()
            accounts.append(nameEmails)
        ob = Solution()
        res = ob.accountsMerge(accounts)
        res.sort()
        print('[', end = '')
        for i in range(len(res)):
            print('[', end = '')
            for j in range(len(res[i])):
                if j != (len(res[i]) - 1):
                    print(res[i][j], end = ', ')
                else:
                    print(res[i][j], end='')
            if (i != len(res) - 1):
                print('], ')
            else:
                print(']', end = '')
        print(']')
# } Driver Code Ends
