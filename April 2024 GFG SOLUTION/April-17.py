#User function Template for python3

class Solution:
    def merge(self, arr, temp, left, mid, right):
        inv_count = 0
        i = left
        j = mid
        k = left
        while i <= mid - 1 and j <= right:
            if arr[i] <= arr[j]:
                temp[k] = arr[i]
                i += 1
                k += 1
            else:
                temp[k] = arr[j]
                k += 1
                j += 1
                inv_count += mid - i
        while i <= mid - 1:
            temp[k] = arr[i]
            i += 1
            k += 1
        while j <= right:
            temp[k] = arr[j]
            k += 1
            j += 1
        for i in range(left, right + 1):
            arr[i] = temp[i]
        return inv_count

    def _mergeSort(self, arr, temp, left, right):
        inv_count = 0
        if right > left:
            mid = (right + left) // 2
            inv_count = self._mergeSort(arr, temp, left, mid)
            inv_count += self._mergeSort(arr, temp, mid + 1, right)
            inv_count += self.merge(arr, temp, left, mid + 1, right)
        return inv_count

    def countPairs(self, arr, n):
        for i in range(n):
            arr[i] = i * arr[i]
        temp = [0] * n
        return self._mergeSort(arr, temp, 0, n - 1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob= Solution()
        print(ob.countPairs(a, n))

        T -= 1


if __name__ == "__main__":
    main()
    
# } Driver Code Ends
