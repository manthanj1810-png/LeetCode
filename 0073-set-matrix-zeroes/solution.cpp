class Solution {
public:
void set(int r,int c,vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++) matrix[i][c]=0;
    for(int i=0;i<matrix[0].size();i++) matrix[r][i]=0;
}
bool check(int r,int c,vector<int> &row,vector<int> &col){
    if(row[r] && col[c]) return true;
    return false;
}
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
       queue<pair<int,int>> q;
       vector<int> visr(n,0), visc(m,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0) q.push({i,j});
        }
       }
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        if(!check(r,c,visr,visc)){
            set(r,c,matrix);
            visr[r]=1;
            visc[c]=1;
        }
    }
    }
};
