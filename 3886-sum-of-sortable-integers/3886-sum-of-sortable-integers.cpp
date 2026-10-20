class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        int total_sum = 0;
        for (int k : divisors) {
            bool is_sortable = true;
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int drop_idx = -1;
                for (int j = 0; j < k; ++j) {
                    if (nums[i + j] > nums[i + (j + 1) % k]) {
                        drops++;
                        drop_idx = j;
                    }
                }
                if (drops > 1) {
                    is_sortable = false;
                    break;
                }
                int start_idx = (drops == 1) ? (drop_idx + 1) % k : 0;
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (start_idx + j) % k] != sorted_nums[i + j]) {
                        is_sortable = false;
                        break;
                    }
                }
                if (!is_sortable) break;
            }
            if (is_sortable) {
                total_sum += k;
            }
        }
        return total_sum;
    }
};