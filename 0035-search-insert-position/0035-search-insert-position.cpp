class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l= 0;
        int r= nums.size()-1;
        while(l<=r){
            if(nums[l+(r-l)/2] ==  target){
                return (l+(r-l)/2);
            }
            else if(nums[l+(r-l)/2]<target){
                l=(l+(r-l)/2) +1;
            }
            else{
                r= (l+(r-l)/2)-1;
            }
        }
        return l;
    }
};