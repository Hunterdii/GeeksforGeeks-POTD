class Solution {
    public int totalElements(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0, maxLen = 0;
        for (int j = 0; j < arr.length; j++) {
            mp.put(arr[j], mp.getOrDefault(arr[j], 0) + 1);
            while (mp.size() > 2) {
                mp.put(arr[i], mp.get(arr[i]) - 1);
                if (mp.get(arr[i]) == 0) mp.remove(arr[i]);
                i++;
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }
        return maxLen;
    }
}
