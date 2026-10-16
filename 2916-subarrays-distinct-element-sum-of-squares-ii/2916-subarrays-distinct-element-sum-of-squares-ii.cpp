class Solution {
    long long MOD = 1e9 + 7;
    vector<long long> tree_sum;
    vector<long long> tree_sq;
    vector<long long> lazy;
    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        int mid = (start + end) / 2;
        int left = 2 * node;
        int right = 2 * node + 1;
        long long val = lazy[node];
        tree_sq[left] = (tree_sq[left] + 2 * val * tree_sum[left] + val * val % MOD * (mid - start + 1)) % MOD;
        tree_sum[left] = (tree_sum[left] + val * (mid - start + 1)) % MOD;
        lazy[left] = (lazy[left] + val) % MOD;
        tree_sq[right] = (tree_sq[right] + 2 * val * tree_sum[right] + val * val % MOD * (end - mid)) % MOD;
        tree_sum[right] = (tree_sum[right] + val * (end - mid)) % MOD;
        lazy[right] = (lazy[right] + val) % MOD;

        lazy[node] = 0;
    }
    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree_sq[node] = (tree_sq[node] + 2 * val * tree_sum[node] + val * val % MOD * (end - start + 1)) % MOD;
            tree_sum[node] = (tree_sum[node] + val * (end - start + 1)) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push(node, start, end);
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
        tree_sq[node] = (tree_sq[2 * node] + tree_sq[2 * node + 1]) % MOD;
    }
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree_sum.assign(4 * n, 0);
        tree_sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        unordered_map<int, int> last_pos;
        long long total_sum = 0;
        for (int j = 0; j < n; ++j) {
            int last_idx = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            update(1, 0, n - 1, last_idx + 1, j, 1);
            total_sum = (total_sum + tree_sq[1]) % MOD;
            last_pos[nums[j]] = j;
        }
        return (total_sum + MOD) % MOD;
    }
};