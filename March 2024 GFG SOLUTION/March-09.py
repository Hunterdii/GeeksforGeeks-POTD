Today's GFG problem Solution in Python


class Solution:

    #Function to find the nth character in the given pattern.
    def nthCharacter(self, s, r, n):

        n += 1
        f = ""
        it = 0
        l = 0

        #loop to find the length of the sequence based on r value.
        while l<n:
            it += 1
            l = it * pow(2, r)
        
        p = pow(2, r)

        #updating n value based on the length of the sequence.
        n -= 1
        n %= p
        
        if it == 0:
            it += 1

        #appending the character at the ith position to the output string.
        f += s[it - 1]

        #loop to generate the sequence by iterating r times.
        for i in range(r):
            s = ""
            for j in range(len(f)):
                if f[j] == '1':
                    s += "10"
                else:
                    s += "01"
            f = s

        #returning the nth character from the generated sequence.
        return f[n]
