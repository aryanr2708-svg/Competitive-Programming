class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum=*min_element(nums.begin(),nums.end());
        int m=0;
        for(int n:nums){
            m+=(n-minnum);
        }
        return m;
    }
};