class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>de;
            for(int j=i;j<nums.size();j++){
                de.insert(nums[j]);
                int dc=de.size();
                sum+=dc*dc;
            }
        }
        return sum;
    }
};