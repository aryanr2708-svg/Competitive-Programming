class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        if(x==0){
            return 0;
        }else{
            while((long)i*i<=x){
            i++;
        }
        return (i-1);
        }
    }
};