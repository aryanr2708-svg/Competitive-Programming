class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>res(2*nums.size());
        for(int i=0;i<nums.size();i++){
            res[i]=nums[i];
            res[i+nums.size()]=nums[i];
        }
        return res;
    }
};