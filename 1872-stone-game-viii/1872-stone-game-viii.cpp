class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0);
        int cm = total;
        int curr = total;
        for(int  i=stones.size()-1;i>1;i--){
            curr-=stones[i];
            cm = max(cm,curr-cm);
        }
        return cm;
    }
};