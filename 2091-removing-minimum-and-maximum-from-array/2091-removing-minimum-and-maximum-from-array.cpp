class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int minv = nums[0];
        int maxv = nums[0];
        int mini = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minv){
                minv = nums[i];
                mini = i;
            }
            if(nums[i]>maxv){
                maxv = nums[i];
                maxi = i;
            }
        }
        int l = min(mini,maxi);
        int r = max(mini,maxi);
        int fo = r+1;
        int bo = nums.size()-l;
        int bs= l+1+nums.size()-r;
        return min({fo,bo,bs});
    }
};