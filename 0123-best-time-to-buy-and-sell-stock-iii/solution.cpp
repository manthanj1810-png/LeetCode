class Solution {
public:
    int solve(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==size(prices) || k==2) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int profit=0;
        if(buy==0){
            profit=max(solve(i+1,0,k,prices,dp),-prices[i]+solve(i+1,1,k,prices,dp));
        }
        if(buy==1){
            profit=max(solve(i+1,1,k,prices,dp),prices[i]+solve(i+1,0,k+1,prices,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(size(prices),vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,0,0,prices,dp);
    }
};
