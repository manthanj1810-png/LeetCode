class Solution {
public:
    int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
      priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
      int n=heights.size(),m=heights[0].size();
      vector<vector<int>> dist(n,vector<int>(m,1e9));
      pq.push({0,{0,0}});
      dist[0][0]=0;
      while(!pq.empty()){
        auto [d,pos]=pq.top();
        auto[i,j]=pos;
        pq.pop();
        if(i==n-1 && j==m-1) return d;
        for(int k=0;k<4;k++){
            int r=i+dr[k],c=j+dc[k];
            if(r>=0 && c>=0 && r<n && c<m){
                int req=max(abs(heights[r][c]-heights[i][j]),d);
                if(req<dist[r][c]){
                    dist[r][c]=req;
                    pq.push({req,{r,c}});
                }
            }
        }
      }
      return 0; 
    }
};
