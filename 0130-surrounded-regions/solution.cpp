class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c,
             vector<vector<char>>& grid,
             vector<vector<bool>>& vis,
             bool &touchBoundary,
             vector<pair<int,int>> &cells) {

        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = true;
        cells.push_back({r, c});

        if (r == 0 || r == m-1 || c == 0 || c == n-1)
            touchBoundary = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !vis[nr][nc] &&
                grid[nr][nc] == 'O') {

                dfs(nr, nc, grid, vis, touchBoundary, cells);
            }
        }
    }

    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (grid[i][j] == 'O' && !vis[i][j]) {
                    bool touchBoundary = false;
                    vector<pair<int,int>> cells;

                    dfs(i, j, grid, vis, touchBoundary, cells);

                    if (!touchBoundary) {
                        for (auto &p : cells) {
                            grid[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};

