class Solution:
    def catchThieves(self, arr, k):
        i = j = c = 0
        n = len(arr)
        while i < n and j < n:
            while i < n and arr[i] != 'P':
                i += 1
            while j < n and arr[j] != 'T':
                j += 1
            if i < n and j < n and abs(i - j) <= k:
                i += 1
                j += 1
                c += 1
            elif j < i:
                j += 1
            else:
                i += 1
        return c
