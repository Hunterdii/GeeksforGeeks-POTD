#User function Template for python3
class Solution:
    def sameFreq(self, s):
        M = 26  # size of hash map for all 26 letters
        
        freq = [0] * M
        for char in s:
            freq[self.getIdx(char)] += 1

        if self.allSame(freq, M):
            return True

        
        for c in range(ord('a'), ord('z') + 1):
            i = self.getIdx(chr(c))
            
            if freq[i] > 0:
                freq[i] -= 1

                if self.allSame(freq, M):
                    return True
                freq[i] += 1

        return False

    
    def getIdx(self, ch):
        return ord(ch) - ord('a')

    
    def allSame(self, freq, N):
        for i in range(N):
            if freq[i] > 0:
                same = freq[i]
                break

        for j in range(i + 1, N):
            if freq[j] > 0 and freq[j] != same:
                return False

        return True


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
	T=int(input())

	for _ in range(T):
		s = input()
		ob = Solution()
		answer = ob.sameFreq(s)
		if answer:
			print(1)
		else:
			print(0)

# } Driver Code Ends
