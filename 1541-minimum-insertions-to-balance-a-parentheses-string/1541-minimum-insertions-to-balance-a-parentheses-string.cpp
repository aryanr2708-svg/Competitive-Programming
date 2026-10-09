class Solution {
public:
    int minInsertions(string s) {
        int b=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                b++;
            }
            else{
                if(i+1<s.size() &&  s[i+1]==')'){
                    i++;
                }
                else{
                    ans++;
                }
                if(b>0){
                    b--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans+(b*2);
    }
};