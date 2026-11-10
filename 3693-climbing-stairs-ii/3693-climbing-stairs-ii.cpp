class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==0){
            return 0;
        }
        vector<int>dp(n+1,0);
        for( int i=1;i<=n;i++){
            int j1=dp[i-1]+costs[i-1]+1;
            int j2=(i>=2)?dp[i-2]+costs[i-1]+4:INT_MAX;
            int j3=(i>=3)?dp[i-3]+costs[i-1]+9:INT_MAX;
            dp[i]=min({j1,j2,j3});
        }
        return dp[n];
    }
};