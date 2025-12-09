
class Solution:
    def findDuplicates(self, arr):
        res = []
        for i in range(len(arr)):
            index = abs(arr[i]) - 1  # Map value to index
            if arr[index] < 0:
                res.append(index + 1)  # Duplicate found
            else:
                arr[index] = -arr[index]  # Mark as visited
        return res
