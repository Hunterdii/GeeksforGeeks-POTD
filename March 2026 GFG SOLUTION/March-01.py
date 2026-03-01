class Solution:
    def pushZerosToEnd(self, arr):
        pos = 0
        for i in range(len(arr)):
            if arr[i] != 0:
                arr[pos] = arr[i]
                pos += 1
        while pos < len(arr):
            arr[pos] = 0
            pos += 1
