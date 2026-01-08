class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
     int m=size(mat),n=size(mat[0]),st=mat[0][0],end=mat[m-1][n-1];
     int strow=0,lstcol=n-1;
     while(strow<=m-1 && lstcol>=0){
        int mid=mat[strow][lstcol];
        if(target==mid){
            return true;
        }else if(target>mid){
            strow++;
        }else lstcol--;
     }
     return false;  
    }
};
