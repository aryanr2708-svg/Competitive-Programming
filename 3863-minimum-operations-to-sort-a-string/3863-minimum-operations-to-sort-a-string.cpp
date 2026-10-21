class Solution {
public:
    int minOperations(string s) {
       if(s.size()<=2 && (!(is_sorted(s.begin(),s.end())))) {
        return -1;
       }
       if(is_sorted(s.begin(),s.end())){
        return 0;
       }
       char min_char=s[0];
       char max_char=s[0];
        for(char c:s){
            if(c<min_char){
               min_char=c;
        }
        if(c>max_char){
            max_char =c;
        }
        }
        if(s[0]==min_char||s[s.size()-1]==max_char){
            return 1;
        }
        if(s[0]==max_char && s[s.size()-1]==min_char){
            bool c2= false;
            for(int i=1;i<s.size()-1;i++){
                if(s[i]==min_char||s[i]==max_char){
                    c2=true;
                    break;
                }
            }
            if(c2){
                return 2;
            }
            return 3;
        }
        return 2;
    }
};