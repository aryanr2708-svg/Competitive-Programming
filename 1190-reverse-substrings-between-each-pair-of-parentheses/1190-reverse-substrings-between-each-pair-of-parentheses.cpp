class Solution {
public:
    string reverseParentheses(string s) {
        string l="";
        for(char c:s){
            if(c==')'){
                string t="";
                while(!l.empty() && l.back()!='('){
                    t+=l.back();
                    l.pop_back();
                }
                if(!l.empty()){
                    l.pop_back();
                }
                l+=t;
            }
            else{
                l.push_back(c);
            }
        }
        return l;
    }
};