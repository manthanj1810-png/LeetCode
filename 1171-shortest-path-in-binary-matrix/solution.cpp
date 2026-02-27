class Solution {
public:
    int dr[8]={-1,-1,0,1,1,1,0,-1};
    int dc[8]={0,1,1,1,0,-1,-1,-1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;  // mark visited and store distance
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            if(r == n-1 && c == n-1)
                return grid[r][c];
            
            for(int i=0;i<8;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        
        return -1;
    }
};
