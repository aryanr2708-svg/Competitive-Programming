class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> pnums(nums.size());
        for(int i=0;i<nums.size();i++){
            pnums[i]={nums[i],i};
        }
        sort(pnums.begin(),pnums.end());
        vector<int>res(nums.size());
        int i=0;
        while(i<nums.size()){
            int j=i+1;
            while(j<nums.size() && pnums[j].first - pnums[j-1].first <= limit){
                j++;
            }
            vector<int> gi;
            for (int k = i; k < j; k++) {
                gi.push_back(pnums[k].second);
            }
            sort(gi.begin(), gi.end());
            for (int k = i; k < j; k++) {
                res[gi[k - i]] = pnums[k].first;
            }
            i = j;
        }
        return res;
    }
};