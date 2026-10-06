class Solution {
public:
    int minAddToMakeValid(string s) {
        int oc=0;
        int m=0;
        for(char c:s){
            if(c=='('){
                oc++;
            }
            else{
                if(oc>0){
                    oc--;
                }
                else{
                    m++;
                }
            }
        }
        return m+oc;
    }
};