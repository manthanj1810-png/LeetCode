class DisjointSet{
    public:
    vector<int> parent, size;
    DisjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findup(int u){
        if(u==parent[u]) return u;
        return parent[u]=findup(parent[u]);
    }
    void join(int u,int v){
        int up_u=findup(u), up_v=findup(v);
        if(up_u==up_v){
            return;
        }
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }
};
class Solution {
    int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
public:
    int largestIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       DisjointSet ds(n*n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int u=i*n+j;
            if(grid[i][j]==1){
                for(int k=0;k<4;k++){
                    int r=i+dr[k],c=j+dc[k];
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==1){
                        int v=r*n+c;
                        ds.join(u,v);
                    }
                }
            }
        }
       }
       int maxi=-1;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            set<int> s;
            int cnt=0;
            if(grid[i][j]==0){
                for(int k=0;k<4;k++){
                    int r=i+dr[k],c=j+dc[k];
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==1){
                        int v=r*n+c;
                        s.insert(ds.findup(v));
                    }
                }
            }
            for(int x:s){
                    cnt+=ds.size[x];
                }
            maxi=max(maxi,cnt+1);
        }
       }
       for(int i=0;i<n*n;i++){
        maxi=max(maxi,ds.size[ds.findup(i)]);
        }
       return maxi;
    }
};
