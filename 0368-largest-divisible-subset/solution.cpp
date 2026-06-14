class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
      for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int t=0;
            if(j==-1 || nums[i]%nums[j]==0) t=1+dp[i+1][i+1];
            int nt= dp[i+1][j+1];
            dp[i][j+1]=max(t,nt);
        }
      } 
      int i=0,j=-1;
      vector<int> ans;
      while(i<n){
        int t=0;
        if(j==-1 || nums[i]%nums[j]==0) t=1+dp[i+1][i+1];
        int nt=dp[i+1][j+1];
        if(t>=nt && (j==-1 || nums[i]%nums[j]==0)){
            ans.push_back(nums[i]);
            j=i;
        }
        i++;
      }
      return ans;
    }
};
