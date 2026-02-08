class Solution {
public:
    void dfshelper(int u, vector<bool> &vis,vector<vector<int>> &lst){
        vis[u]=true;
        for(int v:lst[u]){
            if(!vis[v]){
                dfshelper(v,vis,lst);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isconnected) {
        int v=size(isconnected),count=0;
      vector<vector<int>> lst(v);
      for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(isconnected[i][j]==1 && i!=j){
                lst[i].push_back(j);
                lst[j].push_back(i);
            }
        }
      }
      vector<bool> vis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfshelper(i,vis,lst);
            }
        }
        return count;
    }
};
