class Solution {
public:
    int solve(int i,int j,vector<int>& prices,vector<vector<int>> &dp){
        if(i>=size(prices)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int profit=0;
        if(!j){
            profit=max(solve(i+1,0,prices,dp),-prices[i]+solve(i+1,1,prices,dp));
        }
        else{
            profit=max(solve(i+1,1,prices,dp),prices[i]+solve(i+2,0,prices,dp));
        }
        return dp[i][j]= profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(size(prices),vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
