class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m=size(cuts);
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));
        int cost=0;
        for(int i=m;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i>j) continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                    cost= cuts[j+1]-cuts[i-1] + dp[i][k-1]+ dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][m];
    }
};
