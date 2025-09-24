class SpecialQueue {
    Queue<Integer> q = new LinkedList<>();
    Deque<Integer> mn = new ArrayDeque<>(), mx = new ArrayDeque<>();
    
    public void enqueue(int x) {
        q.offer(x);
        while (!mn.isEmpty() && mn.peekLast() > x) mn.pollLast();
        mn.offerLast(x);
        while (!mx.isEmpty() && mx.peekLast() < x) mx.pollLast();
        mx.offerLast(x);
    }
    
    public void dequeue() {
        int f = q.poll();
        if (f == mn.peekFirst()) mn.pollFirst();
        if (f == mx.peekFirst()) mx.pollFirst();
    }
    
    public int getFront() { return q.peek(); }
    public int getMin() { return mn.peekFirst(); }
    public int getMax() { return mx.peekFirst(); }
}
