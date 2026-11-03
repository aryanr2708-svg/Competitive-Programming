class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxnum=*max_element(nums.begin(),nums.end());
        int m=0;
        for(int n:nums){
            m+=(maxnum-n);
        }
        return m;
    }
};