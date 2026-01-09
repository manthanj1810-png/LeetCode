class Solution {
public:
    int maxincol(vector<vector<int>>& mat,int col){
        int m=size(mat),max=-1,rowindex;
        for(int i=0;i<m;i++){
            if(mat[i][col]>max){
                max=mat[i][col];
                rowindex=i;
            }
        }
        return rowindex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int m=size(mat),n=size(mat[0]),low=0,end=n-1;
      while(low<=end){
        int mid=low+(end-low)/2;
        int row= maxincol(mat,mid);
        int left = mid-1>=0 ? mat[row][mid-1]:-1;
        int right=mid+1<n ? mat[row][mid+1]:-1;
        if(mat[row][mid]>left &&mat[row][mid]>right){
            return {row,mid};
        }else if(mat[row][mid]<left){
            end=mid-1;
        }else low=mid+1;
      }
      return {-1,-1};  
    }
};
