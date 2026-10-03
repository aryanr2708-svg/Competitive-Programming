class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        long int dd = abs((long int)dividend);
        long int dv = abs((long int)divisor);
        int res=0;
        while(dv<=dd){
            long int mul=dv;
            long int temp=1;
            while(mul<=dd-mul){
                mul+=mul;
                temp+=temp;
            }
            res+=temp;
            dd-=mul;
        }
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -res;
        return res;
    }
};