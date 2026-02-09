class Solution {
public:
queue<pair<int,int>> q;
int dr[4]={-1,0,1,0},dc[4]={0,1,0,-1};
void bfs(int sr,int sc,vector<vector<int>>& image,int color,vector<vector<bool>>& vis){
    int m=size(image),n=size(image[0]);
    vis[sr][sc]=true;
    int tc=image[sr][sc];
    image[sr][sc]=color;
    q.push({sr,sc});
    while(!q.empty()){
        auto [a,b]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr= a+dr[i],nc=b+dc[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && image[nr][nc]==tc){
                vis[nr][nc]=true;
                q.push({nr,nc});
                image[nr][nc]=color;
            }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=size(image),n=size(image[0]);
       vector<vector<bool>> vis(m,vector<bool>(n,false)); 
       bfs(sr,sc,image,color,vis);
       return image;
    }
};
