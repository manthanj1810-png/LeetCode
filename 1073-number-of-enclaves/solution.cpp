
    class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c,
             vector<vector<int>>& grid,
             vector<vector<bool>>& vis,
             int &cnt,
             bool &touchBoundary) {

        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = true;
        cnt++;

        if (r == 0 || r == m-1 || c == 0 || c == n-1)
            touchBoundary = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                !vis[nr][nc] &&
                grid[nr][nc] == 1) {

                dfs(nr, nc, grid, vis, cnt, touchBoundary);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cnt = 0;
                    bool touchBoundary = false;
                    dfs(i, j, grid, vis, cnt, touchBoundary);
                    if (!touchBoundary)
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};

