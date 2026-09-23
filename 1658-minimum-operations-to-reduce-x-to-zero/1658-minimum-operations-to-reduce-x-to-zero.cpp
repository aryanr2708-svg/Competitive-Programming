class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ts=accumulate(nums.begin(),nums.end(),0);
        int t=ts-x;
        if(t<0){
            return -1;
        }
        if(t==0){
            return nums.size();
        }
        int cs=0;
        int l=0;
        int ml=-1;
        for(int r=0;r<nums.size();r++){
            cs+=nums[r];
            while(l<=r && cs>t){
                cs-=nums[l];
                l++;
            }

            if(cs==t){
                ml=max(ml,r-l+1);
            }
        }
        return (ml==-1)?-1:nums.size()-ml;
    }
};