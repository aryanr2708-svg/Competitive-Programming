class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(auto it:nums){
            if(k==0 || it!= nums[k-1]){
                nums[k]=it;
                k++;
            }
        }
        return k;
    }
};