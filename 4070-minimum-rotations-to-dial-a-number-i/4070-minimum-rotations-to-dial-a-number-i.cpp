class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        int prev=0;
        for(char c:s){
            int cur=c-'0';
            int d=abs(cur-prev);
            ans+=min(d,10-d);
            prev=cur;
        }
        return ans;
    }
};