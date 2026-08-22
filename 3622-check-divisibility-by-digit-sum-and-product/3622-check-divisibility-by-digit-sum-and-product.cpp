class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int ogn= n;
        while(n>0){
            s+=n%10;
            p*=(n%10);
            n/=10;
        }
        if(s+p==0) return false;
        return (ogn%(s+p))==0;
    }
};