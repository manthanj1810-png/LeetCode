class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Push all initially rotten oranges
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        int minute = 0;

        // BFS level by level
        while(!q.empty() && fresh > 0){
            int sz = q.size();
            minute++;

            for(int k = 0; k < sz; k++){
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return fresh == 0 ? minute : -1;
    }
};

