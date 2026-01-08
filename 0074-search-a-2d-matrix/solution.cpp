class Solution {
public:
    bool searchrow(vector<vector<int>>& mat, int target,int row){
     int y=mat[0].size(),st=0,end=y-1;
     while(st<=end){
        int mid=st+(end-st)/2;
        if(mat[row][mid]==target){
            return true;
        }else if(target<mat[row][mid]){
            end=mid-1;
        }else st=mid+1;
     }
     return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
       int m=size(mat),n=size(mat[0]), strow=0,lstrow=m-1;
       while(strow<=lstrow){
        int midrow=strow+(lstrow-strow)/2;
        if(target<=mat[midrow][n-1] && target>=mat[midrow][0]){
            return searchrow(mat,target,midrow);
        }else if(target<mat[midrow][n-1]){
            lstrow=midrow-1;
        }else strow=midrow+1;
        }
        return false;
    }
};
