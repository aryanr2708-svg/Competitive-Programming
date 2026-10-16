class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<=3){
            return accumulate(nums.begin(), nums.end(), 0);
        }
        sort(nums.begin(),nums.end());
        long long cs=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                long long sum=(long long)nums[i]+nums[l]+nums[r];
            if(sum==target){
                return target;
            }
            if(abs(sum-target)<abs(cs-target)){
                cs=sum;
            }
            if(sum<target){
                l++;
            }
            else{
                r--;
            }
        }
        }
        return cs;
    }
};