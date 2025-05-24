class Solution {
    public static int sumSubstrings(String s) {
        long res=0,f=0;
        for(int i=0;i<s.length();++i){
            f=f*10+(s.charAt(i)-'0')*(i+1);
            res+=f;
        }
        return (int)res;
    }
}
