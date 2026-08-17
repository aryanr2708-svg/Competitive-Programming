class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int ogN = x;
        int revN = 0;
        while (x>0) {
            int ld = x%10;
            if (revN > (INT_MAX - ld) / 10) {
            return false;
        }
            revN = (revN*10)+ld;
            x /=10;
        }
        return ogN == revN;
    }
};