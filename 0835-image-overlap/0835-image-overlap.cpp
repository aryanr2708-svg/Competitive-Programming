class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>o1,o2;
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1.size();j++){
                if(img1[i][j]==1){
                    o1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    o2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int> slide;
        int olap=0;
        for(const auto&p1:o1){
            for(const auto&p2:o2){
                int rs= p2.first-p1.first;
                int cs=p2.second-p1.second;
                slide[{rs,cs}]++;
                olap=max(olap,slide[{rs,cs}]);
            }
        }
        return olap;
    }
};