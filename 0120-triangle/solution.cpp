class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
       vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                long long up=INT_MAX,upl=INT_MAX;
                if(i-1>=0) up=dp[i-1][j]+(long long)triangle[i][j];
                if(i>=1 && j>=1) upl=dp[i-1][j-1]+(long long)triangle[i][j];
                dp[i][j]=min(up,upl);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++) ans=min(ans,dp[n-1][i]);
        return ans;
    }
};
