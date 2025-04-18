//{ Driver Code Starts
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


// } Driver Code Ends

class Trie {
    class N { N[] c = new N[26]; boolean e; }
    N r = new N();
    public void insert(String w) {
        N n = r;
        for (char ch : w.toCharArray())
            n = n.c[ch - 'a'] != null ? n.c[ch - 'a'] : (n.c[ch - 'a'] = new N());
        n.e = true;
    }
    public boolean search(String w) {
        N n = r;
        for (char ch : w.toCharArray())
            if ((n = n.c[ch - 'a']) == null) return false;
        return n.e;
    }
    public boolean isPrefix(String w) {
        N n = r;
        for (char ch : w.toCharArray())
            if ((n = n.c[ch - 'a']) == null) return false;
        return true;
    }
}


//{ Driver Code Starts.

public class GfG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            int q = sc.nextInt();
            sc.nextLine();
            List<Boolean> ans = new ArrayList<>();
            Trie ob = new Trie();

            for (int i = 0; i < q; i++) {
                int x = sc.nextInt();
                String s = sc.next();
                if (i != q - 1) sc.nextLine();

                if (x == 1) {
                    ob.insert(s);
                } else if (x == 2) {
                    ans.add(ob.search(s));
                } else if (x == 3) {
                    ans.add(ob.isPrefix(s));
                }
            }

            for (Boolean result : ans) {
                System.out.print(result + " ");
            }
            System.out.println();
            System.out.println("~");
        }

        sc.close();
    }
}

// } Driver Code Ends
