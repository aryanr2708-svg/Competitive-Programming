class Solution { 
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> v;
        for(int i=0;i<nums.size();i++){
            int c = target-nums[i];
            if(v.count(c)){
                return{v[c],i};
            }
            v[nums[i]]=i;
        }
        return{};
    }
};