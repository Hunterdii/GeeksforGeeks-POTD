Today's Solution of POD in JAVA

class Solution{
    // Function to find the maximum index difference.
    static int maxIndexDiff(int arr[], int n) { 
        if(n==1){
            return 0;
        }
        int RMax[] = new int[n]; 
        int LMin[] = new int[n]; 
        
        //Constructing LMin[] such that LMin[i] stores the minimum value 
        //from (arr[0], arr[1], ... arr[i]).
        LMin[0] = arr[0];
        for (int i = 1; i < n; ++i) 
            LMin[i] = Integer.min(arr[i], LMin[i - 1]);
            
        //Constructing RMax[] such that RMax[j] stores the maximum value 
        //from (arr[j], arr[j+1], ..arr[n-1]). 
        RMax[n - 1] = arr[n - 1]; 
        for (int j = n - 2; j >= 0; --j)
            RMax[j] = Integer.max(arr[j], RMax[j + 1]); 
            
        int i = 0, j = 0, maxDiff = -1; 
        //Traversing both arrays from left to right to find optimum j-i.
        //This process is similar to merge() of MergeSort.
        while (j < n && i < n) { 
            if (LMin[i] <= RMax[j]) { 
                //Updating the maximum difference.
                maxDiff = Integer.max(maxDiff, j - i); 
                j++; 
            } else
                i++;
        }
        //returning the maximum difference.
        return maxDiff; 
    }
}
