class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxw=0;
        long long l=0;
        long long cw =0;
        long long r=height.size()-1;
        while (l < r) {
            cw = (r-l)*min(height[l],height[r]);
            maxw = max(maxw,cw);
            height[l]<height[r]?l++:r--;
        }
        return maxw;
    }
};