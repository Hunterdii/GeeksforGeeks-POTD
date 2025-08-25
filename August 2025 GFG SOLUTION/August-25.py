class Solution:
    def maximizeMedian(self, arr, k):
        arr.sort()
        n = len(arr)
        left = arr[n//2] if n % 2 == 1 else (arr[n//2-1] + arr[n//2]) // 2
        right = left + k
        result = left
        
        while left <= right:
            mid = left + (right - left) // 2
            if self.canAchieve(arr, mid, k):
                result = mid
                left = mid + 1
            else:
                right = mid - 1
        return result
    
    def canAchieve(self, arr, target, k):
        n = len(arr)
        ops = 0
        
        if n % 2 == 1:
            for i in range(n//2, n):
                if arr[i] < target:
                    ops += target - arr[i]
                    if ops > k:
                        return False
        else:
            median_sum = arr[n//2-1] + arr[n//2]
            if 2 * target > median_sum:
                ops += 2 * target - median_sum
                if ops > k:
                    return False
            for i in range(n//2+1, n):
                if arr[i] < target:
                    ops += target - arr[i]
                    if ops > k:
                        return False
        return True
