class Solution:
    def nextGreater(self, arr):
        n = len(arr)
        res = [-1] * n
        stk = []
        for i in range(2 * n):
            while stk and arr[stk[-1]] < arr[i % n]:
                res[stk.pop()] = arr[i % n]
            if i < n:
                stk.append(i)
        return res
