class Solution {
public:
    int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        while(!pq.empty()){
            auto [d,pos]=pq.top();
            pq.pop();
            auto [i,j]=pos;
            for(int k=0;k<4;k++){
                int r=i+dr[k],c=j+dc[k];
                if(r>=0 && r<n && c>=0 && c<n && dist[i][j]!=1e9){
                    int req=max(dist[i][j],grid[r][c]);
                    if(dist[r][c]>req){
                        dist[r][c]=req;
                        pq.push({req,{r,c}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};
