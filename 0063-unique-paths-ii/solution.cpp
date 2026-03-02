class Solution {
public:
    int solve(int x,int y,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
        if(obstacleGrid[x][y]==1) {
            return dp[x][y]=0;
        }
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int down=0,right=0;
        if(x-1>=0)
            down=solve(x-1,y,dp,obstacleGrid);
        if(y-1>=0)
            right=solve(x,y-1,dp,obstacleGrid);
        return dp[x][y]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=size(obstacleGrid), n=size(obstacleGrid[0]);
        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};
