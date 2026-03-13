class Solution {
public:
    bool help(int i,int j,vector<vector<char>>& board, string word,int k){
        if(k==size(word)) return true;
        if(i<0 || j<0 || i>=size(board) || j>=size(board[0])|| board[i][j]!=word[k]) return false;
        char temp=board[i][j];
        board[i][j]='@';
        bool found=help(i-1,j,board,word,k+1) || help(i,j+1,board,word,k+1) || help(i+1,j,board,word,k+1) || help(i,j-1,board,word,k+1);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=size(board), n=size(board[0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(help(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};
