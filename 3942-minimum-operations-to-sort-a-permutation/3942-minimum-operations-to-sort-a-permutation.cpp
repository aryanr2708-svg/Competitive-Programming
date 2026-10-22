class Solution {
public:
    int minOperations(vector<int>& nums) {
       if(nums.size()<=1 ) {
        return 0;
       }
       int zero=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            zero=i;
            break;
        }
       }
       bool inc=true;
       for(int i=0;i<nums.size();i++){
        if(nums[(zero+i)%nums.size()]!=i){
            inc=false;
            break;
        }
       }
       bool dec= true;
       for(int i=0;i<nums.size();i++){
        if(nums[(zero-i+nums.size())%nums.size()]!=i){
            dec= false;
            break;
        }
       }
       if(!inc && !dec){
        return -1;
       }
       int ans= INT_MAX;
       if(inc){
        int dl=zero;
        int dr=(nums.size()-zero)%nums.size();
        ans=min(ans,dl);
        ans=min(ans,dr+2);
       }
       if(dec){
        int dl=(zero+1)%(nums.size());
        int dr=(nums.size()-1-zero+nums.size())%nums.size();
        ans=min(ans,dl+1);
        ans=min(ans,dr+1);
       }
       return ans;
    }
};