class Solution {
public:
    int solve(int i,int j,int k,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==size(prices) ||k==0) return 0;
        int profit=0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        if(!j){
            profit=max(solve(i+1,0,k,prices,dp),-prices[i]+solve(i+1,1,k,prices,dp));
        }
        else{
            profit=max(solve(i+1,1,k,prices,dp),prices[i]+solve(i+1,0,k-1,prices,dp));
        }
        return dp[i][j][k]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(size(prices),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,0,k,prices,dp);
    }
};
