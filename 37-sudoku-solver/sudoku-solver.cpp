class Solution {
public:
    bool isSafe(vector<vector<char>>& board , int row , int col, int val){
        // for row
        int n = board.size();
        for(int i = 0; i< n;i++){
            if( board[row][i] == (char)(val + '0') ){
                return false;
            }
        }

        // for col
        for( int i=0; i<n; i++){
            if( board[i][col] == (char)(val + '0')){
                return false;
            }
        }

        // 3x3 matrix
        for( int i=0; i<n; i++){
            if(board[ 3*(row/3) + i/3 ][ 3*(col/3) + i%3 ] == (char)(val + '0')){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for( int row = 0; row < n; row++){
            for( int col = 0; col <n; col++){


                // cell is empty
                if(board[row][col] == '.'){
                    for( int val = 1; val <= 9; val++){
                        if(isSafe(board, row, col, val)){
                            board[row][col] = (char)(val + '0');
                            bool aglaSolPos = solve(board);
                            if(aglaSolPos){
                                return true;
                            }
                            else{
                                board[row][col] = '.';
                            }
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