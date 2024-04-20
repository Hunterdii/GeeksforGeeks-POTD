#User function Template for python3
class Solution:
    #Function to return a list containing the union of the two arrays.
    def findUnion(self, arr1, arr2, n, m):
    
        '''
        :param a: given sorted array a
        :param n: size of sorted array a
        :param b: given sorted array b
        :param m: size of sorted array b
        :return:  The union of both arrays as a list
        '''
        arr1.sort()
        arr2.sort()
        
        ans = []
        
        i = 0
        j = 0
        
        while i < n and j < m:
            if arr1[i] < arr2[j]:
                ans.append(arr1[i])
                i += 1
            elif arr1[i] > arr2[j]:
                ans.append(arr2[j])
                j += 1
            else:
                ans.append(arr1[i])
                i += 1
                j += 1
        
        while i < n:
            ans.append(arr1[i])
            i += 1
        
        while j < m:
            ans.append(arr2[j])
            j += 1
        
        # Remove duplicates
        result = []
        for k in range(len(ans)):
            if k == 0 or ans[k] != ans[k - 1]:
                result.append(ans[k])
        
        return result

        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

# Contributed by : Nagendra Jha
# Modified by : Sagar Gupta


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,m = map(int,input().strip().split())
        a = list(map(int,input().strip().split()))
        b = list(map(int,input().strip().split()))
        ob=Solution()
        li = ob.findUnion(a,b,n,m)
        for val in li:
            print(val, end = ' ')
        print()
# } Driver Code Ends
