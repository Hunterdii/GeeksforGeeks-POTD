class Solution:
    def sumSubstrings(self,s):
        res=f=0
        for i,ch in enumerate(s):
            f=f*10+int(ch)*(i+1)
            res+=f
        return res
