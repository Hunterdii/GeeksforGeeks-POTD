#User function Template for python3

# arr    : list of integers denoting the elements of the array
# target : as specified in the problem statement

class Solution:
    def threeSumClosest(self, arr, target):
        arr.sort()
        closest_sum = float('inf')
        n = len(arr)

        for i in range(n - 2):
            left, right = i + 1, n - 1

            while left < right:
                current_sum = arr[i] + arr[left] + arr[right]

                if current_sum == target:
                    return current_sum

                if abs(current_sum - target) < abs(closest_sum - target) or (
                    abs(current_sum - target) == abs(closest_sum - target) and current_sum > closest_sum):
                    closest_sum = current_sum

                if current_sum < target:
                    left += 1
                else:
                    right -= 1

        return closest_sum
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.threeSumClosest(A, k))

# } Driver Code Ends
