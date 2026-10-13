class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>sq(nums.size());
        for(int i=0;i<nums.size();i++){
            sq[i]=nums[i]*nums[i];
        }
        sort(sq.begin(),sq.end());
        int minus=nums.size()/2;
        long long sc=0;
        for (int i=0;i<minus;i++) {
            sc-=sq[i];
        }
        for(int i=minus;i<nums.size();i++){
            sc+=sq[i];
        }
        return sc;
    }
};