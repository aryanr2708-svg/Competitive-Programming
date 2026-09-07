class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return{};
        }
        string pmap[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>output;
        backtrack("",digits,pmap,output);
        return output;
    }
    private:
    void  backtrack(string combi,string nd,string pmap[], vector<string>&output){
        if(nd.empty()){
            output.push_back(combi);
        }
        else{
            string l=pmap[nd[0]-'2'];
            for(char c:l){
                backtrack(combi+c,nd.substr(1),pmap,output);
            }
        }
    }
};