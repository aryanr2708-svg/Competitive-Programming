class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        int nn =sum/9;
        int rem=sum%9;
        int n=num-nn-(rem>0?1:0);
        string res="";
        res.append(nn,'9');
        if(rem>0){
            res.push_back('0'+rem);
        }
        res.append(n,'0');
        return res; 
    }
};