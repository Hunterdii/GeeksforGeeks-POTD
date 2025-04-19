class Solution:
    def maxXor(self, arr):
        class TrieNode:
            __slots__ = ['children']
            def __init__(self):
                self.children = [None, None]
        
        root = TrieNode()
        
        for num in arr:
            node = root
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                if not node.children[bit]:
                    node.children[bit] = TrieNode()
                node = node.children[bit]
        
        max_xor = 0
        for num in arr:
            node = root
            current_xor = 0
            for i in range(31, -1, -1):
                bit = (num >> i) & 1
                desired_bit = 1 - bit
                if node.children[desired_bit]:
                    current_xor |= (1 << i)
                    node = node.children[desired_bit]
                else:
                    node = node.children[bit]
            max_xor = max(max_xor, current_xor)
        return max_xor

2)
class Solution:
    def maxXor(self, nums):
        max_xor, mask = 0, 0
        for i in range(30, -1, -1):
            mask |= (1 << i)
            prefixes = set(num & mask for num in nums)
            candidate = max_xor | (1 << i)
            if any((candidate ^ p) in prefixes for p in prefixes):
                max_xor = candidate
        return max_xor

3)
class Solution:
    def maxXor(self, arr):
        max_xor, mask = 0, 0
        for i in range(30, -1, -1):
            mask |= (1 << i)
            prefixes = set()
            temp = max_xor | (1 << i)
            found = False
            for num in arr:
                prefix = num & mask
                if (temp ^ prefix) in prefixes:
                    found = True
                    break
                prefixes.add(prefix)
            if found:
                max_xor = temp
        return max_xor
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.maxXor(arr))
        print("~")

# } Driver Code Ends
