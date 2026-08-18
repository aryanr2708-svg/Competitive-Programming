class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> sc;
        int l = -1;
        for(int i=0;i<=nums.size()-k;i++){
            unordered_set<int> sb(nums.begin()+i,nums.begin()+k+i);
            for(int n:sb){
                sc[n]++;
            }
        }
        for(auto [n,c]:sc){
            if(c==1){
                l=max(l,n);
            }
        }
        return l;
    }
};