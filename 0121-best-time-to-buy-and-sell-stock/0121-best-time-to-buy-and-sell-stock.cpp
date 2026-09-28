class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp=INT_MAX;
        int maxpfit=0;
        for(int p:prices){
            minp=min(minp,p);
            int cp=p-minp;
            maxpfit=max(maxpfit,cp);
        }
        return maxpfit;
    }
};