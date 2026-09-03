class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_num = INT_MAX;
        bool odd= false;
        for(auto n:nums1){
            if(n%2){
                odd = true;
                min_num=min(min_num,n);
            }
        }
        if(!odd){
            return true;
        }
        for(int n:nums1){
            if(n%2==0 && min_num>n){
                return false;
            }
        }
        return true;
    }
};