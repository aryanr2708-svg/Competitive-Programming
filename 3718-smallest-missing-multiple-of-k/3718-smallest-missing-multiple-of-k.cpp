class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>ns(nums.begin(),nums.end());
        int m = k;
        while(ns.count(m)){
            m+=k;
        }
        return m;
    }
};