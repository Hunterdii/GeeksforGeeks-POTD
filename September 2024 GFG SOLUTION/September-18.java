//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class Driverclass
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        //Reading total number of testcases
        int t= sc.nextInt();
        
        while(t-- >0)
        {
            //reading the string
            String st = sc.next();
            
            //calling ispar method of Paranthesis class 
            //and printing "balanced" if it returns true
            //else printing "not balanced"
            if(new Solution().ispar(st) == true)
                System.out.println("balanced");
            else
                System.out.println("not balanced");
        
        }
    }
}
// } Driver Code Ends



class Solution
{
    static boolean ispar(String x)
    {
        Stack<Character> s = new Stack<>();
        
        for (char c : x.toCharArray()) {
            switch(c) {
                case '(': case '{': case '[':
                    s.push(c);
                    break;
                case ')':
                    if (s.isEmpty() || s.pop() != '(') return false;
                    break;
                case '}':
                    if (s.isEmpty() || s.pop() != '{') return false;
                    break;
                case ']':
                    if (s.isEmpty() || s.pop() != '[') return false;
                    break;
            }
        }
        return s.isEmpty();
    }
}
