class Solution {
public:
    int maxPalindromes(string s, int k) {
        int end=-1;
        int c=0;
        if(k==1){
            return s.size();
        }
        for(int i=0;i<s.size();i++){
            for(int j:{i-1,i}){
                int l=i;
                while(j>=0 &&  l<s.size() && s[j]==s[l]){
                    if(l+1-j>=k && j>end){
                        c++;
                        end=l;
                        break;
                    }
                    j--;
                    l++;
                }
            }
        }
        return c;
    }
};