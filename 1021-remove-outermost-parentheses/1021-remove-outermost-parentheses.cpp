class Solution {
public:
    string removeOuterParentheses(string s) {
        int l =0;
        string res="";
        for(char c:s){
            if(c=='('){
                if(l>0){
                    res+=c;
                }
                l++;
            }
            else if(c==')'){
                l--;
                if(l>0){
                    res+=c;
                }
            }
        }
        return res;
    }
};