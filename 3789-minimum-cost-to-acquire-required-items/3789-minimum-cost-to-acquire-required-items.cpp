class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1=cost1,c2=cost2,cb=costBoth, n1= need1,n2=need2;
        long long o1=c1*n1+n2*c2;
        long long minN=min(n1,n2);
        long long o2=minN*cb+(n1-minN)*c1+(n2-minN)*c2;
        long long maxN=max(n1,n2);
        long long o3=cb*maxN;
        return min({o1,o2,o3});
    }
};