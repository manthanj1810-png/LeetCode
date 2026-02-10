class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=size(graph);
        vector<int> indeg(v,0);
        vector<int> ans;
        vector<vector<int>> g(v);
        queue<int> q;
        for(int i=0;i<v;i++){
            for(int j:graph[i]){
                g[j].push_back(i);
                indeg[i]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(int x:g[curr]){
                indeg[x]--;
                if(indeg[x]==0) q.push(x);
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};
