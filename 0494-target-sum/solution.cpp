class Solution {
public:
    int solve(int i,int k ,vector<int>& arr,vector<vector<int>>& dp){
    if(i == 0){
            if(k == 0 && arr[0] == 0) return 2;
            if(k == 0 || k== arr[0]) return 1;
            return 0;
        }
    if(dp[i][k]!=-1) return dp[i][k];
    int take=0,ntake=solve(i-1,k,arr,dp);
    if(arr[i]<=k){
        take=solve(i-1,k-arr[i],arr,dp);
    }
    return dp[i][k]=take+ntake;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0),count=0;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        for(int i=0;i<=sum;i++){
            if(!solve(nums.size()-1,i,nums,dp)) continue;
            if(target==sum-2*i){
                count+=solve(nums.size()-1,i,nums,dp);
            }
        }
        return count++;
    }
};
