class Solution {
public:
    void combos(int target, vector<int>& cur,vector<int>& candidates,int id, vector<vector<int>>& res){
        if(target==0){
            res.push_back(cur);
            return;
        }
        for(int i=id;i<candidates.size();i++){
            if(candidates[i]>target){
                break;
            }
            cur.push_back(candidates[i]);
            combos(target-candidates[i],cur,candidates,i,res);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>cur;
        sort(candidates.begin(),candidates.end());
        combos(target,cur,candidates ,0,res);
        return res;
    }
};