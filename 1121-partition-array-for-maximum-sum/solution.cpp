class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=size(arr);
        vector<int> dp(n+1,0);
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--){
            int len=0,ans=INT_MIN,maxi=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum= maxi*len + dp[j+1];
                ans=max(ans,sum);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};
