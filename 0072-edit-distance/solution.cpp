class Solution {
public:
    int solve(int i,int j,string s1, string s2, vector<vector<int>> &dp){
        if(j>=s2.size()) return s1.size()-i;
        if(i>=s1.size()) return s2.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        int r=INT_MAX,in=INT_MAX,d=INT_MAX;
        if(s1[i]==s2[j]) return solve(i+1,j+1,s1,s2,dp);
        
            r=solve(i+1,j+1,s1,s2,dp)+1;
            d=solve(i+1,j,s1,s2,dp)+1;
            in=solve(i,j+1,s1,s2,dp)+1;

        return dp[i][j]= min({r,d,in});
    }
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s1,s2,dp);
    }
};
