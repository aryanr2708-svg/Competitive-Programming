class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        if(x==0){
            return 0;
        }
        int l=1;
        int r=x;
        int n = 0;
        while(l<=r){
            int m = l+ (r-l)/2;
            if((long)m*m<=x){
                n=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return n;
    }
};