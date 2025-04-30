class Solution {
    public int countNodesinLoop(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return countLoopLength(slow);
            }
        }
        return 0;
    }
  
    private int countLoopLength(Node node) {
        int count = 1;
        Node temp = node;
        while (temp.next != node) {
            count++;
            temp = temp.next;
        }
        return count;
    }
}
