class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxw=0;
        long long l=0;
        long long r=height.size()-1;
        while (l < r) {
            long long w= r - l;
            long long ch = min(height[l], height[r]);
            maxw = max(maxw, ch * w);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxw;
    }
};