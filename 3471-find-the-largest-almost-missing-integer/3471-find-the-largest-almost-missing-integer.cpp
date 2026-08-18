class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> sc;
        if(k==nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        for(int n:nums){
            sc[n]++;
        }
        if(k==1){
            int l = -1;
            for(auto [n,c]:sc){
                if(c==1){
                   l=max(l,n);
                }
            }
            return l;
        }
        int l = -1;
        
        if (sc[nums.front()] == 1) {
            l = max(l, nums.front());
        }
        if (sc[nums.back()] == 1) {
            l = max(l, nums.back());
        }
        
        return l;
    }
};