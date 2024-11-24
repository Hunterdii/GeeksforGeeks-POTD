//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline character

        while (t-- > 0) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            List<Integer> nums = new ArrayList<>();
            for (String part : parts) {
                nums.add(Integer.parseInt(part));
            }
            Solution ob = new Solution();
            List<Integer> ans = ob.findMajority(nums);
            for (int num : ans) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
// } Driver Code Ends

class Solution {

    public List<Integer> findMajority(List<Integer> nums) {
        int n = nums.size();
        List<Integer> res = new ArrayList<>();

        if (n == 0) return Arrays.asList(-1); 

        int num1 = -1, num2 = -1, c1 = 0, c2 = 0;

        for (int x : nums) {
            if (x == num1) {
                c1++;
            } else if (x == num2) {
                c2++;
            } else if (c1 == 0) {
                num1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                num2 = x;
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        for (int x : nums) {
            if (x == num1) c1++;
            else if (x == num2) c2++;
        }

        if (c1 > n / 3) res.add(num1);
        if (c2 > n / 3) res.add(num2);

        if (res.isEmpty()) res.add(-1); 

        return res;
    }
}
