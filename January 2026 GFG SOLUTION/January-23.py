class Solution:
    def maxPeople(self, arr):
        n = len(arr)
        l, r, s = [1] * n, [1] * n, []
        for i in range(n):
            while s and arr[s[-1]] < arr[i]: l[i] += l[s.pop()]
            s.append(i)
        s.clear()
        for i in range(n - 1, -1, -1):
            while s and arr[s[-1]] < arr[i]: r[i] += r[s.pop()]
            s.append(i)
        return max(l[i] + r[i] - 1 for i in range(n))
