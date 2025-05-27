class Solution:
    def leafNodes(self, preorder):
        s, r = [], []
        for i in range(len(preorder)-1):
            f = False
            if preorder[i] > preorder[i+1]:
                s.append(preorder[i])
            else:
                while s and preorder[i+1] > s[-1]:
                    s.pop()
                    f = True
            if f:
                r.append(preorder[i])
        r.append(preorder[-1])
        return r
