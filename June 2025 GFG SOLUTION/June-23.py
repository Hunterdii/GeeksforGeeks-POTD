class Solution:
    def minSum(self, arr):
        count = [0]*10
        for x in arr: count[x]+=1
        s1 = s2 = ""
        first = True
        for d in range(10):
            while count[d]>0:
                if first:
                    if s1 or d!=0: s1 += str(d)
                    first = False
                else:
                    if s2 or d!=0: s2 += str(d)
                    first = True
                count[d] -= 1
        if not s1: s1="0"
        if not s2: s2="0"
        return self.addString(s1, s2)
    def addString(self, s1, s2):
        i, j, carry, res = len(s1)-1, len(s2)-1, 0, []
        while i>=0 or j>=0 or carry>0:
            if i>=0: carry += int(s1[i]); i-=1
            if j>=0: carry += int(s2[j]); j-=1
            res.append(str(carry%10))
            carry//=10
        while len(res)>1 and res[-1]=='0': res.pop()
        return ''.join(reversed(res))
