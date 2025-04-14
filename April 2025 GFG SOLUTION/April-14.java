//{ Driver Code Starts
// Initial Template for Java
import java.util.*;


// } Driver Code Ends

class Solution {
    public String findOrder(String[] w) {
        List<List<Integer>> g = new ArrayList<>();
        int[] in = new int[26];
        boolean[] seen = new boolean[26];
        for (int i = 0; i < 26; i++) g.add(new ArrayList<>());
        for (String s : w) for (char c : s.toCharArray()) seen[c - 'a'] = true;
        for (int i = 0; i < w.length - 1; i++) {
            String a = w[i], b = w[i + 1];
            int j = 0, n = Math.min(a.length(), b.length());
            while (j < n && a.charAt(j) == b.charAt(j)) j++;
            if (j == n && a.length() > b.length()) return "";
            if (j < n) {
                g.get(a.charAt(j) - 'a').add(b.charAt(j) - 'a');
                in[b.charAt(j) - 'a']++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < 26; i++) if (seen[i] && in[i] == 0) q.add(i);
        StringBuilder res = new StringBuilder();
        while (!q.isEmpty()) {
            int u = q.poll();
            res.append((char)(u + 'a'));
            for (int v : g.get(u)) if (--in[v] == 0) q.add(v);
        }
        for (int i = 0; i < 26; i++) if (seen[i] && in[i] > 0) return "";
        return res.toString();
    }
}


//{ Driver Code Starts.

public class GFG {
    private static boolean validate(String[] original, String order) {
        Map<Character, Integer> mp = new HashMap<>();
        for (String word : original) {
            for (char ch : word.toCharArray()) {
                mp.put(ch, 1);
            }
        }
        for (char ch : order.toCharArray()) {
            if (!mp.containsKey(ch)) {
                return false;
            }
            mp.remove(ch);
        }
        if (!mp.isEmpty()) {
            return false;
        }

        Map<Character, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            indexMap.put(order.charAt(i), i);
        }

        for (int i = 0; i < original.length - 1; i++) {
            String a = original[i];
            String b = original[i + 1];
            int k = 0, n = a.length(), m = b.length();

            while (k < n && k < m && a.charAt(k) == b.charAt(k)) {
                k++;
            }

            if (k < n && k < m &&
                indexMap.get(a.charAt(k)) > indexMap.get(b.charAt(k))) {
                return false;
            }
            if (k != n && k == m) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine()); // Number of test cases

        while (t-- > 0) {
            String[] words = sc.nextLine().split(" ");
            String[] original = Arrays.copyOf(words, words.length);

            Solution ob = new Solution();
            String order = ob.findOrder(words);

            if (order.isEmpty()) {
                System.out.println("\"\"");
            } else {
                System.out.println(validate(original, order) ? "true" : "false");
            }
            System.out.println("~");
        }

        sc.close();
    }
}

// } Driver Code Ends
