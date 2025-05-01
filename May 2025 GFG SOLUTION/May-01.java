class Solution {

    ArrayList<Integer> nthRowOfPascalTriangle(int n) {
        ArrayList<Integer> row = new ArrayList<>();
        row.add(1);
        long value = 1;

        for (int k = 1; k < n; k++) {
            value = value * (n - k);
            value = value / k;
            row.add((int) value);
        }
        return row;
    }
}
