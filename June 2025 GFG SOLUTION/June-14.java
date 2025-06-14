/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}

*/

class Solution {
    public boolean isSymmetric(Node root) {
        if (root == null) return true;
        Stack<Node> s1 = new Stack<>(), s2 = new Stack<>();
        s1.push(root.left);
        s2.push(root.right);
        while (!s1.isEmpty() && !s2.isEmpty()) {
            Node a = s1.pop(), b = s2.pop();
            if (a == null && b == null) continue;
            if (a == null || b == null || a.data != b.data) return false;
            s1.push(a.left); s2.push(b.right);
            s1.push(a.right); s2.push(b.left);
        }
        return s1.isEmpty() && s2.isEmpty();
    }
}

2)
class Solution {
    boolean isSym(Node a, Node b){
        if(a==null||b==null) return a==b;
        if(a.data!=b.data) return false;
        return isSym(a.left,b.right)&&isSym(a.right,b.left);
    }
    public boolean isSymmetric(Node r){
        return r==null||isSym(r.left,r.right);
    }
}

// 3) Solution @itsjomon
class Solution {
    public boolean isSymmetric(Node root) {
        if (root == null) return true;
        return isMirror(root.left, root.right);
    }

    private boolean isMirror(Node t1, Node t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.data == t2.data)
            && isMirror(t1.left, t2.right)
            && isMirror(t1.right, t2.left);
    }
}
