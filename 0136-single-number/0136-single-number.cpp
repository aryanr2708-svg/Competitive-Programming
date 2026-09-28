class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n:nums){
            mp[n]++;
        }
        for(auto n:mp){
            if(n.second==1){
                return n.first;
            }
        }
        return -1;
    }
};