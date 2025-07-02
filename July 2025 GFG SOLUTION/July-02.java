class Solution {
    public int totalElements(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 0, max = 0;
        for (int j = 0; j < arr.length; j++) {
            map.put(arr[j], map.getOrDefault(arr[j], 0) + 1);
            while (map.size() > 2) {
                map.put(arr[i], map.get(arr[i]) - 1);
                if (map.get(arr[i]) == 0) map.remove(arr[i]);
                i++;
            }
            max = Math.max(max, j - i + 1);
        }
        return max;
    }
}
