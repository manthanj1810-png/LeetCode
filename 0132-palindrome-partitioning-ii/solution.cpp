class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n,false));

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])){
                    pal[i][j]=true;
                }
            }
        }

        vector<int> dp(n+1,0);
        dp[n] = -1;

        for(int i=n-1;i>=0;i--){
            int minc = INT_MAX;

            for(int j=i;j<n;j++){
                if(pal[i][j]){
                    minc = min(minc, 1 + dp[j+1]);
                }
            }

            dp[i] = minc;
        }

        return dp[0];
    }
};
