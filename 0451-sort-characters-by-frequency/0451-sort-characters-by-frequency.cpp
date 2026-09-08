class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(auto c:s){
            freq[c]++;
        }
        string ans="";
        while(!freq.empty()){
            char maxc=0;
            int maxf=0;
            for(auto it:freq){
                if(it.second>maxf){
                    maxf=it.second;
                    maxc=it.first;
                }
            }
            while(maxf--){
                ans.push_back(maxc);
            }
            freq.erase(maxc);
        }
        return ans;
    }
};