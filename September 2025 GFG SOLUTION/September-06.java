/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    public int lengthOfLoop(Node head) {
        Node s = head, f = head;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
            if (s == f) {
                int len = 0;
                do {
                    f = f.next;
                    len++;
                } while (s != f);
                return len;
            }
        }
        return 0;
    }
}

2)
class Solution {
    public int lengthOfLoop(Node head) {
        Node s = head, f = head;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
            if (s == f) {
                int cnt = 1;
                while (s.next != f) {
                    s = s.next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
}
