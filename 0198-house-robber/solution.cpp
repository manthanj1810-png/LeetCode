class Solution {
public:
    int rob(vector<int>& nums) {
        int n=size(nums);
        if(n==1) return nums[0];
        vector<int> dp(n,INT_MIN);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int npick=dp[i-1];
            int pick=dp[i-2]+nums[i];
            dp[i]=max(pick,npick);
        }
        return dp[n-1];
    }
};
