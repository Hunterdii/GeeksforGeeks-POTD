class Solution {
    public ArrayList<String> possibleWords(int[] arr) {
        ArrayList<String> res = new ArrayList<>();
        res.add("");
        String[] keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int d : arr) {
            if (d < 2 || d > 9) continue;
            ArrayList<String> temp = new ArrayList<>();
            for (String s : res)
                for (char c : keys[d].toCharArray())
                    temp.add(s + c);
            res = temp;
        }
        return res;
    }
}
