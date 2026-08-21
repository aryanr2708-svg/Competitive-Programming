class Solution {
    public int mySqrt(int x) {
        int i = 0;
        while ((long)i*i <= x)
        {
            i += 1;
        }
        return (i-1);
    }
}