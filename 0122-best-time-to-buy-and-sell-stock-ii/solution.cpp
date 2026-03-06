class Solution {
public:
    int solve(int i,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(i==size(prices)) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy==0){
            profit=max(solve(i+1,0,prices,dp),-prices[i]+solve(i+1,1,prices,dp));
        }
        if(buy==1){
            profit=max(solve(i+1,1,prices,dp), prices[i]+solve(i+1,0,prices,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(size(prices),vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
