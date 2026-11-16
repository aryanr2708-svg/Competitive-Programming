class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            string ns="";
            for(int i=0;i<s.length();i+=k){
                int cs=0;
                for(int j=i;j<i+k && j<s.length();j++){
                    cs+=s[j]-'0';
                }
                ns+=to_string(cs);
            }
            s=ns;
        }
        return s;
    }
};