class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &k: knowledge){
            mp[k[0]]=k[1];
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                int j=s.find(')',i+1);
                auto w=s.substr(i+1,j-i-1);
                res+=mp.count(w)? mp[w]:"?";
                i=j;
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};