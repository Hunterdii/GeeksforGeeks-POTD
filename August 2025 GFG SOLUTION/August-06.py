class Solution:
    def romanToDecimal(self, s): 
        vals = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        syms = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        res = i = 0
        for j in range(13):
            while i + len(syms[j]) <= len(s) and s[i:i+len(syms[j])] == syms[j]:
                res += vals[j]
                i += len(syms[j])
        return res
