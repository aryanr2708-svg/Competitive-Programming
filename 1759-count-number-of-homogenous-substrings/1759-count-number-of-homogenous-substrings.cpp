class Solution {
public:
    int countHomogenous(string s) {
        long long ts=0;
        int cur=0;
        long long MOD=1e9+7;
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1]){
                cur++;
            }
            else{
                cur=1;
            }
            ts=(ts+cur)%MOD;
        }
        return static_cast<int>(ts);
    }
};