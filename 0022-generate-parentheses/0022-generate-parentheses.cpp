class Solution {
public:
    void btrk(vector<string>& res,string cur,int o,int c,int n){
        if(cur.length()==n*2){
            res.push_back(cur);
            return;
        }
        if(o<n){
            btrk(res,cur+"(",o+1,c,n);
        }
        if(c<o){
            btrk(res,cur+")",o,c+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        btrk(res,"",0,0,n);
        return res;
    }
};