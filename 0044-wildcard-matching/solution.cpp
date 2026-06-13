class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<bool> dp(m+1,false), prev(m+1,false);
        prev[0]=true;
        for(int i=1;i<=m;i++){
            prev[i]=(prev[i-1] && p[i-1]=='*');
        }
        for(int i=1;i<=n;i++){
            dp[0]=false;
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[j]=prev[j-1];
                else if(p[j-1]=='*'){
                    dp[j]= prev[j] || dp[j-1];
                }
                else dp[j]=false;
            }
            prev=dp;
        }
    return prev[m];
    }
};
