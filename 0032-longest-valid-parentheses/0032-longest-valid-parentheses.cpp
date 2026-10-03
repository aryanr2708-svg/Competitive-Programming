class Solution {
public:
    int longestValidParentheses(string s) {
        int res=0;
        vector<int>stk ={-1};
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push_back(i);
            }
            else{
                stk.pop_back();
                if(stk.empty()){
                    stk.push_back(i);
                }
                else{
                    res=max(res,i-stk.back());
                }
            }
        }
        return res;
    }
};