class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       queue<tuple<int,int,int>> pq;
       pq.push({0,src,0});
       vector<vector<pair<int,int>>> adj(n);
       for(auto &it:flights){
        adj[it[0]].push_back({it[1],it[2]});
       }
       vector<int> cost(n,1e9);
       cost[src]=0;
       while(!pq.empty()){
        auto [stops,node,p]=pq.front();
        pq.pop();
        if(stops>k) continue;
        for(auto &it:adj[node]){
            int v=it.first, wt=it.second;
            if(p+wt<cost[v] && stops<=k){
                cost[v]=p+wt;
                pq.push({stops+1,v,p+wt});
            }
        }
       }
       if(cost[dst]==1e9) return -1;
       return cost[dst]; 
    }
};
