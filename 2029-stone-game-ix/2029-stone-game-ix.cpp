class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {0,0,0};
        for(int s:stones){
            c[s%3]++;
        }
        if (c[0]%2 ==0){
            return c[1]>0 && c[2]>0;
        }
        return abs(c[1]-c[2])>2;
    }
};