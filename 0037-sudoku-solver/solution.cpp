class Solution {
public:
    bool possible(int num,int r,int c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][c]-'0'==num) return false;
        }
        for(int i=0;i<9;i++){
            if(board[r][i]-'0'==num) return false;
        }
        for(int i=3*(r/3);i<(3*(r/3)+3);i++){
            for(int j= 3*(c/3);j<(3*(c/3) +3);j++){
                if(board[i][j]-'0'==num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(possible(k,i,j,board)){
                            board[i][j]=k+'0';
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
