class Solution {
public:
    
    int calc(vector<vector<int>>&board, int i, int j){
        // horizontal sides and vertical sides checked 
        int ln = 0;
        if(i > 0 && (board[i-1][j] == 1 || board[i-1][j] == 3)){
            ln++;
        }
        if(j > 0 && (board[i][j-1] == 1 || board[i][j-1] == 3)){
            ln++;
        }
        if(i < board.size()-1 && (board[i+1][j] == 1 || board[i+1][j] == 3)){
            ln++;
        }
        if(j < board[i].size()-1 && (board[i][j+1] == 1 || board[i][j+1] == 3)){
            ln++;
        }
        // upper left diagonal
        if(i-1 >= 0 && j-1 >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 3)){
            ln++;
        }
        // lower right diagonal
        if((i+1 <= board.size()-1 && j+1 <= board[i].size()-1) && (board[i+1][j+1] == 1 || board[i+1][j+1] == 3)){
            ln++;
        }
        // upper right 
        if((i-1 >= 0 && j+1 <= board[i].size()-1) && (board[i-1][j+1] == 1 || board[i-1][j+1] == 3)){
            ln++;
        }
        // lower left
        if((i+1 <= board.size()-1 && j - 1 >= 0) && (board[i+1][j-1] == 1 || board[i+1][j-1] == 3)){
            ln++;
        }
        return ln;
    }
    

    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int ln = calc(board,i,j);
                if(board[i][j] == 1){
                    if(ln < 2 || ln > 3){
                        board[i][j] = 3;
                    }    
                }
                else if(board[i][j] == 0){
                    if(ln == 3){
                        board[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 3){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 2){
                    board[i][j] = 1;
                }
            }
        }
    }
};