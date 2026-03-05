class Solution {
public:
    int solve(int i,int amount,vector<int>& coins,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0) return 1;
            return 0;
        }
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int ntake=solve(i-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[i]){
            take=solve(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]= take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(begin(coins),end(coins));
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};
