class Solution {
public:
    bool solve(int i,int k,vector<int>& nums,vector<vector<int>> &dp){
        if(k==0) return true;
        if(i==0) return(nums[0]==k);
        if(dp[i][k]!=-1) return dp[i][k];
        int nt=solve(i-1,k,nums,dp);
        int t=false;
        if(nums[i]<=k){
            t=solve(i-1,k-nums[i],nums,dp);
        }
        return dp[i][k]=t | nt;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2 + 1,-1));
        return solve(nums.size()-1,sum/2,nums,dp);
    }
};
