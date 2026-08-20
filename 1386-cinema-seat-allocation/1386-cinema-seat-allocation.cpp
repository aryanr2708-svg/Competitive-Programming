class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> seats;
        for(auto s:reservedSeats){
            int r = s[0];
            int c = s[1];
            if(c>=2 && c<=9){
               seats[r].insert(c); 
            }
        }
        int f = 2*n;
        for(auto p:seats){
            auto rc = p.second;
            bool l = !rc.count(2)  && !rc.count(3) && !rc.count(4) && !rc.count(5);
            bool r = !rc.count(6)  && !rc.count(7) && !rc.count(8) && !rc.count(9);
            bool ctr = !rc.count(4)  && !rc.count(5) && !rc.count(6) && !rc.count(7);
            if(l && r){
            }
            else if(l||r||ctr){
                f-=1;
            }
            else{
                f-=2;
            }
        }
        return  f;
    }
};