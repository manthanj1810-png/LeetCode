class Solution {
public:
int dr[3]={1,1,1}, dc[3]={1,0,-1};
    int solve(int i,int j,int k,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int n=grid.size(),s=grid[0].size();
        if(i==n-1){
            if(j!=k) return grid[i][j]+grid[i][k];
            else return grid[i][j];
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int maxi=INT_MIN;
        for(int m=0;m<3;m++){
            int cr=dr[m]+i, cc1=dc[m]+j;
            for(int l=0;l<3;l++){
                int cc2=dc[l]+k;
                if(cr>=0 && cr<n && cc1>=0 && cc1<s && cc2>=0 && cc2<s){
                    if(k==j){
                        maxi=max(maxi,grid[i][j]+solve(cr,cc1,cc2,grid,dp));
                    }else{
                        maxi=max(maxi,grid[i][j]+grid[i][k]+solve(cr,cc1,cc2,grid,dp));
                    }
                }
            }
        }
        return dp[i][j][k]= maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};
