class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<bool>> &vis){
        int m=size(grid),n=size(grid[0]);
        vis[x][y]=true;
        int nr[4]={-1,0,1,0};
        int nc[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r= x+nr[i],c=y+nc[i];
            if(r>=0 && r<m && c>=0 && c<n && !vis[r][c] && grid[r][c]=='1'){
                dfs(r,c,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
       int m=size(grid),n=size(grid[0]),count=0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};
