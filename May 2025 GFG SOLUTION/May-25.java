class Solution {
    public boolean pythagoreanTriplet(int[] arr) {
        HashSet<Integer> squares = new HashSet<>();
        for (int x : arr) squares.add(x * x);
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (squares.contains(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
}
