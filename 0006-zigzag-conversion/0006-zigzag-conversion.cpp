class Solution {
public:
    string convert(string s, int n) {
        if(n==1 || n>=s.length()){
            return s;
        }
        vector<string>sd(n,"");
        int r = 0;
        bool down = true;
        for(int i=0;i<s.length();i++){
            sd[r]+=s[i];
            if(down){
                r++;
                if(r==n){
                    r-=2;
                    down = false;
                }
            }
            else{
                r--;
                if(r<0){
                    r=1;
                    down = true;
                }
            }
        }
        string res="";
        for(int i =0;i<n;i++){
            res+=sd[i];
        }
        return res;
    }
};