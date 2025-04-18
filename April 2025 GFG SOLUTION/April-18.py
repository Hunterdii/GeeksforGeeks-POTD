class Trie:
    class N:
        def __init__(self): self.c, self.e = [None]*26, 0
    def __init__(self): self.r = self.N()
    def insert(self, w):
        n = self.r
        for ch in w:
            i = ord(ch)-97
            n.c[i] = n.c[i] or self.N()
            n = n.c[i]
        n.e = 1
    def search(self, w):
        n = self.r
        for ch in w:
            i = ord(ch)-97
            if not n.c[i]: return 0
            n = n.c[i]
        return n.e
    def isPrefix(self, w):
        n = self.r
        for ch in w:
            i = ord(ch)-97
            if not n.c[i]: return 0
            n = n.c[i]
        return 1


#{ 
 # Driver Code Starts
def main():
    t = int(input())
    for _ in range(t):
        q = int(input())
        ans = []
        trie = Trie()

        for _ in range(q):
            x, s = input().split()
            x = int(x)

            if x == 1:
                trie.insert(s)
            elif x == 2:
                ans.append(trie.search(s))
            elif x == 3:
                ans.append(trie.isPrefix(s))

        # Print results as lowercase true/false
        print(" ".join(["true" if res else "false" for res in ans]))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
