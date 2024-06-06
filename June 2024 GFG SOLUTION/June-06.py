#User function Template for python3

def max_sum(a, n):
    total_sum = sum(a)
    
    curr_sum = 0
    for i in range(n):
        curr_sum += i * a[i]
    
    max_sum_value = curr_sum
    for i in range(1, n):
        curr_sum = curr_sum + total_sum - n * a[n - i]
        max_sum_value = max(max_sum_value, curr_sum)
    
    return max_sum_value


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        print(max_sum(arr, n))

# } Driver Code Ends
