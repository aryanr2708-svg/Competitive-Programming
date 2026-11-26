class Solution {
public:
    bool canAliceWin(int n) {
        int stones =10;
        bool al=true;
        while(n>=stones && stones>0){
            n-=stones;
            stones--;
            al=!al;
        }
        return !al;
    }
};