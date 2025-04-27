class Solution:
    def multiplyStrings(self, s1, s2):
        sign=-1 if (s1[0]=='-')^(s2[0]=='-') else 1
        if s1[0]=='-': s1=s1[1:]
        if s2[0]=='-': s2=s2[1:]
        s1=s1.lstrip('0'); s2=s2.lstrip('0')
        if not s1 or not s2: return "0"
        n,m=len(s1),len(s2); r=[0]*(n+m)
        for i in range(n-1,-1,-1):
            for j in range(m-1,-1,-1):
                r[i+j+1]+=int(s1[i])*int(s2[j])
        for i in range(n+m-1,0,-1):
            r[i-1]+=r[i]//10; r[i]%=10
        i=0
        while i<len(r) and r[i]==0: i+=1
        ans=''.join(str(x) for x in r[i:])
        return "-"+ans if sign<0 else ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        a = input()
        b = input()
        print(Solution().multiplyStrings(a.strip(), b.strip()))

        print("~")

# } Driver Code Ends
