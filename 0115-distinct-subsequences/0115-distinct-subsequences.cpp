unsigned sq[1001];
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned long long>cc(t.size()+1);
        cc[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int  j=t.size();j>=1;j--){
                if(s[i-1]==t[j-1]){
                    cc[j]+=cc[j-1];
                }
            }
        }
        return static_cast<int>(cc[t.size()]);
    }
};