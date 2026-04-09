class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<pair<int,int>> p;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    p.push_back({i,j});
                }
            }
        }
        for(auto &it:p){
            int i=it.first,j=it.second;
            for(int a=0;a<n;a++){
                matrix[i][a]=0;
            }
            for(int b=0;b<m;b++){
                matrix[b][j]=0;
            }
        }
    }
};
