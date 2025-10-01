class Solution:
    def uniquePerms(self, arr):
        arr.sort()
        res = []
        def next_permutation(nums):
            n = len(nums)
            i = n - 2
            while i >= 0 and nums[i] >= nums[i + 1]:
                i -= 1
            if i < 0:
                return False
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1:] = reversed(nums[i + 1:])
            return True
        res.append(arr[:])
        while next_permutation(arr):
            res.append(arr[:])
        return res
