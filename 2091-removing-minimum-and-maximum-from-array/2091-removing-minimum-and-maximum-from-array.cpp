class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int minf=distance(nums.begin(),min_element(nums.begin(),nums.end()));
        int minb=nums.size()-minf;
        int maxf=distance(nums.begin(),max_element(nums.begin(),nums.end()));
        int maxb=nums.size()-maxf;
        int bs = (minf<maxf)? (minf+1+maxb):(maxf+1+minb);
        int fo = max(minf,maxf)+1;
        int bo = max(minb,maxb);
        return  min({fo,bo,bs});
    }
};