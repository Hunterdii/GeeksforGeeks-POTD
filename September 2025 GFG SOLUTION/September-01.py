class Solution:
    def sumOfModes(self, arr, k):
        n, sum_val = len(arr), 0
        freq = defaultdict(int)
        buckets = defaultdict(set)
        
        for i in range(k):
            freq[arr[i]] += 1
        
        for val, f in freq.items():
            buckets[f].add(val)
        
        max_freq = max(buckets.keys())
        sum_val += min(buckets[max_freq])
        
        for i in range(k, n):
            out, in_val = arr[i - k], arr[i]
            
            buckets[freq[out]].remove(out)
            if not buckets[freq[out]]:
                del buckets[freq[out]]
            
            freq[out] -= 1
            if freq[out] > 0:
                buckets[freq[out]].add(out)
            else:
                del freq[out]
            
            if freq[in_val] > 0:
                buckets[freq[in_val]].remove(in_val)
                if not buckets[freq[in_val]]:
                    del buckets[freq[in_val]]
            
            freq[in_val] += 1
            buckets[freq[in_val]].add(in_val)
            
            max_freq = max(buckets.keys())
            sum_val += min(buckets[max_freq])
        
        return sum_val
