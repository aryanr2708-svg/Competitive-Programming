class Solution {
    int n, k;
    struct Node {
        int prod_mod;
        int cnt[5][5];
        Node() {
            prod_mod = 1;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    cnt[i][j] = 0;
                }
            }
        }
    };
    vector<Node> tree;
    void merge(Node& parent, const Node& left, const Node& right) {
        parent.prod_mod = (left.prod_mod * right.prod_mod) % k;
        for (int rem = 0; rem < k; ++rem) {
            for (int target = 0; target < k; ++target) {
                int left_cnt = left.cnt[rem][target];
                int mid_rem = (rem * left.prod_mod) % k;
                int right_cnt = right.cnt[mid_rem][target];
                parent.cnt[rem][target] = left_cnt + right_cnt;
            }
        }
    }
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem_val = val % k;
            tree[node].prod_mod = rem_val;
            for (int rem = 0; rem < k; ++rem) {
                for (int target = 0; target < k; ++target) {
                    tree[node].cnt[rem][target] = 0;
                }
                int target = (rem * rem_val) % k;
                tree[node].cnt[rem][target] = 1; 
            }
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        merge(tree[node], tree[2 * node], tree[2 * node + 1]);
    }
    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) return query(2 * node, start, mid, l, r);
        if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);
        Node left_res = query(2 * node, start, mid, l, mid);
        Node right_res = query(2 * node + 1, mid + 1, end, mid + 1, r);
        Node res;
        merge(res, left_res, right_res);
        return res;
    }
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;
        tree.assign(4 * n, Node());
        for (int i = 0; i < n; ++i) {
            update(1, 0, n - 1, i, nums[i]);
        }
        vector<int> result;
        result.reserve(queries.size());
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, start, n - 1);
            result.push_back(res.cnt[1%k][x]);
        }
        return result;
    }
};