class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        if(nums.size()==0){
            return -1;
        }
        vector<int>minsuf(nums.size());
        minsuf[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            minsuf[i]=min(nums[i],minsuf[i+1]);
        }
        int curmax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curmax = max(curmax,nums[i]);
            int isc=curmax-minsuf[i];
            if(isc<=k){
                return i;
            }
        }
        return -1;
    }
};