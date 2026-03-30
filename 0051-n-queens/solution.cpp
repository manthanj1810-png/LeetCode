class Solution {
public:
    bool safe(vector<string> &t,int r,int c,int n){
        for(int j=0;j<n;j++){
            if(t[r][j]=='Q') return false;
        }
        for(int i=0;i<n;i++){
            if(t[i][c]=='Q') return false;
        }
        for(int j=c,i=r;j>=0 && i>=0;j--,i--){
            if(t[i][j]=='Q') return false;
        }
        for(int j=c,i=r;j<n && i>=0;j++,i--){
            if(t[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(vector<vector<string>> &res,vector<string> &t, int r,int n){
        if(r==n){
            res.push_back(t);
            return;
        }
        for(int j=0;j<n;j++){
            if(safe(t,r,j,n)){
                t[r][j]='Q';
                helper(res,t,r+1,n);
                t[r][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> t(n,string(n,'.'));
        vector<vector<string>> res;
        helper(res,t,0,n);
        return res;
    }
};
