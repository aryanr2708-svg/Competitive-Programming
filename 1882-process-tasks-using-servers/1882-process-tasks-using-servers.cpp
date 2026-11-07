class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> free_servers;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> busy_servers;
        for(int i=0;i<n;i++){
            free_servers.push({servers[i],i});
        }
        vector<int>ans(m);
        long long t=0;
        for(int j=0;j<m;j++){
            t=max(t,(long long)j);
            if(free_servers.empty()){
                t=max(t,busy_servers.top().first);
            }
            while(!busy_servers.empty() && busy_servers.top().first<=t){
                free_servers.push(busy_servers.top().second);
                busy_servers.pop();
            }
            auto[weight,id]=free_servers.top();
            free_servers.pop();
            ans[j]=id;
            busy_servers.push({t+tasks[j],{weight,id}});
        }
        return ans;
    }
};