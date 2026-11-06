class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int nq = queries.size();
        vector<int> ans(nq);
        vector<pair<int,int>> sortedq(nq);
        for(int i=0;i<nq;i++){
            sortedq[i]={queries[i],i};
        }
        sort(sortedq.begin(),sortedq.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> sc(n+1,0);
        int us=0;
        int l=0;
        int r=0;
        int nlogs=logs.size();
        for(const auto& q:sortedq){
            int qt=q.first;
            int qid=q.second;
            int ws=qt-x;
            int we=qt;
            while(r<nlogs && logs[r][1]<=we){
                int sid=logs[r][0];
                if(sc[sid]==0){
                    us++;
                }
                sc[sid]++;
                r++;
            }
            while(l<nlogs && logs[l][1]<ws){
                int sid=logs[l][0];
                sc[sid]--;
                if(sc[sid]==0){
                    us--;
                }
                l++;
            }
            ans[qid]=n-us;
        }
        return ans;
    }
};