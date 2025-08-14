class Solution:
    def countRevPairs(self, arr):
        def mergeSort(l, r):
            if l >= r: return 0
            m = (l + r) // 2
            return mergeSort(l, m) + mergeSort(m + 1, r) + merge(l, m, r)
        
        def merge(l, m, r):
            cnt = j = 0
            for i in range(l, m + 1):
                while m + 1 + j <= r and arr[i] > 2 * arr[m + 1 + j]: j += 1
                cnt += j
            arr[l:r+1] = sorted(arr[l:r+1])
            return cnt
        
        return mergeSort(0, len(arr) - 1)
