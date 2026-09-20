class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int i=1;
        for(char c:s){
            sum+=(26-(c-'a'))*i;
            i++;
        }
        return sum;
    }
};