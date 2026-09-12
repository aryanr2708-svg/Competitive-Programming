#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Interval {
        int l, r, weight, id;
    };
    struct State {
        long long weight = 0;
        vector<int> selected;
    };
    bool isBetter(const State& a, const State& b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        return a.selected < b.selected;
    }
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(sorted_intervals.begin(), sorted_intervals.end(), [](const Interval& a, const Interval& b) {
            return a.r < b.r;
        });
        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int i = 1; i <= n; ++i) {
            const auto& curr = sorted_intervals[i - 1];
            int p = 0;
            int low = 0, high = i - 2;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (sorted_intervals[mid].r < curr.l) {
                    p = mid + 1; 
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            for (int j = 1; j <= 4; ++j) {
                State opt1 = dp[i - 1][j];
                State opt2;
                opt2.weight = dp[p][j - 1].weight + curr.weight;
                opt2.selected = dp[p][j - 1].selected;
                opt2.selected.push_back(curr.id);
                sort(opt2.selected.begin(), opt2.selected.end());
                if (isBetter(opt2, opt1)) {
                    dp[i][j] = opt2;
                } else {
                    dp[i][j] = opt1;
                }
            }
        }
        return dp[n][4].selected;
    }
};
