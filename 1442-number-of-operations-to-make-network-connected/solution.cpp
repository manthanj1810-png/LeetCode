class Solution {
public:
    void dfs(int u,vector<bool>& vis,vector<vector<int>>& adj){
        vis[u]=true;
        for(auto v:adj[u]){
            if(!vis[v]){
            dfs(v,vis,adj);
        }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      int e=size(connections),count=0;
      vector<bool> vis(n,false);
      vector<vector<int>> adj(n);
        for(int i=0;i<e;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }
        if(e<(n-1)) return -1;
        return count-1;
    }
};
