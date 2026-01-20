class Solution {
    StringBuilder d = new StringBuilder();
    Stack<Character> r = new Stack<>();
    
    public void append(char x) {
        d.append(x);
        r.clear();
    }
    
    public void undo() {
        if (d.length() > 0) {
            r.push(d.charAt(d.length() - 1));
            d.deleteCharAt(d.length() - 1);
        }
    }
    
    public void redo() {
        if (!r.isEmpty()) {
            d.append(r.pop());
        }
    }
    
    public String read() {
        return d.toString();
    }
}
