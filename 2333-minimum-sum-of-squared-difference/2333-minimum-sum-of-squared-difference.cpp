class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> diffs(n);
        long long max_diff = 0;
        long long total_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            max_diff = max(max_diff, diffs[i]);
            total_diff += diffs[i];
        }
        if (total_diff <= k) {
            return 0;
        }
        vector<long long> bucket(max_diff + 1, 0);
        for (long long d : diffs) {
            bucket[d]++;
        }
        for (long long i = max_diff; i > 0; --i) {
            if (bucket[i] > 0) {
                long long take = min(k, bucket[i]);
                bucket[i] -= take;
                bucket[i - 1] += take;
                k -= take;
            }
            if (k == 0) {
                break;
            }
        }
        long long min_squared_sum = 0;
        for (long long i = 1; i <= max_diff; ++i) {
            if (bucket[i] > 0) {
                min_squared_sum += bucket[i] * (i * i);
            }
        }
        return min_squared_sum;
    }
};
