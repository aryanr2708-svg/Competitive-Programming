class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        auto get_valid_end = [&](int i) {
            int right = last[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                if (first[s[j] - 'a'] < i) return -1;
                right = max(right, last[s[j] - 'a']);
            }
            return right;
        };
        vector<pair<int, int>> intervals;
        for (int i = 0; i < s.length(); ++i) {
            if (i == first[s[i] - 'a']) {
                int res = get_valid_end(i);
                if (res != -1) {
                    intervals.push_back({res, i});
                }
            }
        }
        sort(intervals.begin(), intervals.end());
        
        vector<string> ans;
        int prev_end = -1;
        for (const auto& interval : intervals) {
            int right = interval.first;
            int left = interval.second;
            if (left > prev_end) {
                ans.push_back(s.substr(left, right - left + 1));
                prev_end = right;
            }
        }
        return ans;
    }
};