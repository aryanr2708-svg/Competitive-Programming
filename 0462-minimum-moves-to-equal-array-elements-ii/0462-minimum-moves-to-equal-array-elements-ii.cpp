class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid =nums.begin()+nums.size()/2;
        nth_element(nums.begin(),mid,nums.end());
        int median =*mid;
        int m=0;
        for(int n:nums){
            m+=abs(n-median);
        }
        return m;
    }
};