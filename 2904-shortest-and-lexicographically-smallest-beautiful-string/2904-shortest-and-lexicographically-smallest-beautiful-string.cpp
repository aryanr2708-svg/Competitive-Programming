class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        for(int i =0;i<s.size();i++){
            int c=0;
            string cur="";
            for(int j =i;j<s.size();j++){
                cur+=s[j];
                if(s[j]=='1'){
                    c++;
                }
                if(c>k){
                    break;
                }
                if(c==k){
                    if(ans==""||cur.size()<ans.size()||(cur.size()==ans.size() && cur<ans)){
                        ans=cur;
                    }
                }
            }
        }
        return ans;
    }
};