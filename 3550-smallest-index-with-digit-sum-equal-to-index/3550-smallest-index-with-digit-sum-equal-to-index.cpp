class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int i=0;
        for(int n:nums){
            int sum=0;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            if(sum==i) return i;
            else i++;
        }
        return -1;
    }
};