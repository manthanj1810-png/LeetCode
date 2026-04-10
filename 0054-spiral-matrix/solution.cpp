class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> ans;
       int m=matrix.size(),n=matrix[0].size();
       int top=0,bottom=m-1,left=0,right=n-1;
       while(left<=right && top<=bottom){
        for(int j=left;j<=right;j++) ans.push_back(matrix[top][j]); //right
        for(int i=top+1;i<=bottom;i++) ans.push_back(matrix[i][right]);  //down
        if(top<bottom) for(int j=right-1;j>=left;j--) ans.push_back(matrix[bottom][j]); //left;
        if(left<right) for(int i=bottom-1;i>=top+1;i--) ans.push_back(matrix[i][left]); //up;
        top++;
        bottom--;
        left++;
        right--;
       }
       return ans;
    }
};
