#User function Template for python3
from typing import List

class Solution:
    def findOrder(self, dict: List[str], n: int, k: int) -> str:
        adj = [[] for _ in range(k)]
        for i in range(1, n):
            self.buildGraph(adj, dict[i - 1], dict[i])
        
        visited = [False] * k
        st = []
        for i in range(k):
            if not visited[i]:
                self.topologicalSort(i, adj, visited, st)
        
        order = ""
        while st:
            order += chr(st.pop() + ord('a'))
        return order
    
    def buildGraph(self, adj: List[List[int]], str1: str, str2: str) -> None:
        len_ = min(len(str1), len(str2))
        for i in range(len_):
            if str1[i] != str2[i]:
                adj[ord(str1[i]) - ord('a')].append(ord(str2[i]) - ord('a'))
                break

    def topologicalSort(self, node: int, adj: List[List[int]], visited: List[bool], st: List[int]) -> None:
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.topologicalSort(neighbor, adj, visited, st)
        st.append(node)
#{ 
 # Driver Code Starts
#Initial Template for Python 3


class sort_by_order:

    def __init__(self, s):
        self.priority = {}
        for i in range(len(s)):
            self.priority[s[i]] = i

    def transform(self, word):
        new_word = ''
        for c in word:
            new_word += chr(ord('a') + self.priority[c])
        return new_word

    def sort_this_list(self, lst):
        lst.sort(key=self.transform)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        line = input().strip().split()
        n = int(line[0])
        k = int(line[1])

        alien_dict = [x for x in input().strip().split()]
        duplicate_dict = alien_dict.copy()
        ob = Solution()
        order = ob.findOrder(alien_dict, n, k)
        s = ""
        for i in range(k):
            s += chr(97 + i)
        l = list(order)
        l.sort()
        l = "".join(l)
        if s != l:
            print(0)
        else:
            x = sort_by_order(order)
            x.sort_this_list(duplicate_dict)

            if duplicate_dict == alien_dict:
                print(1)
            else:
                print(0)

# } Driver Code Ends
