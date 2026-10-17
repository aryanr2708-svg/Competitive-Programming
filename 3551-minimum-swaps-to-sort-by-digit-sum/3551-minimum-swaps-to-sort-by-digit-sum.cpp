class Solution {
public:
    static int dsum(int n){
        int s=0;
        while(n>0){
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>ar(nums.size());
        for(int i=0;i<nums.size();i++){
            ar[i]={nums[i],i};
        }
        sort(ar.begin(),ar.end(),[](const auto& a, const auto& b){
            int sumA=dsum(a.first);
            int sumB=dsum(b.first);
            if(sumA!=sumB){
                return sumA<sumB;
            }
            return a.first<b.first;
        });
        int swaps=0;
        for(int i=0;i<nums.size();i++){
            while(ar[i].second!=i){
                swap(ar[i],ar[ar[i].second]);
                swaps++;
            }
        }
        return swaps;
    }
};