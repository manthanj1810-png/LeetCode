class Solution {
public:
    bool dfs(int i,vector<vector<int>>& graph, vector<int> &color, int last){
        color[i]=last;
        for(auto it:graph[i]){
            if(color[it]==-1){
                if(!dfs(it,graph,color,1-last)) return false;
            }
            else if(color[it]==last) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,graph,color,0)) return false;
            }
        }
        return true;
    }
};
