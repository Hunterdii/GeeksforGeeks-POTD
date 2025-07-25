class Solution {
    public int maxCircularSum(int arr[]) {
        int maxKadane = kadane(arr);
        int totalSum = 0;
        for (int i = 0; i < arr.length; i++) {
            totalSum += arr[i];
            arr[i] = -arr[i];
        }
        int maxCircular = totalSum + kadane(arr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = -arr[i];
        }
        return maxCircular == 0 ? maxKadane : Math.max(maxKadane, maxCircular);
    }
    
    private int kadane(int[] arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.length; i++) {
            currSum = Math.max(arr[i], currSum + arr[i]);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }
}
