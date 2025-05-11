class Solution {
    public static int kthLargest(int[] arr, int k) {
        // code here
        int n = arr.length;
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + arr[j];
                
                if(q.size() < k){
                    q.offer(sum);
                }else if(sum > q.peek()){
                    q.poll();
                    q.offer(sum);
                }
            }
        }
        return q.peek();
    }
}
