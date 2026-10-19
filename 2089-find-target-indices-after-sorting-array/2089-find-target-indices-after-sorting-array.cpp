class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lc=0,e=0;
        for(int n:nums){
            if(n<target){
                lc++;
            }
            else if(n==target){
                e++;
            }
        }
        vector<int>ans;
        for(int i=0;i<e;i++){
            ans.push_back(lc+i);
        }
        return ans;
    }
};