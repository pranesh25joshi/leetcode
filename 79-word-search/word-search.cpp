class Solution {
public:
    bool searchNext(vector<vector<char>>& board, string& word, int row, int col, int index, int m, int n) {
        // if we matched all characters
        if (index == word.length())
            return true;

        // boundary + mismatch check
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[index])
            return false;

        // store current char & mark visited
        char c = board[row][col];
        board[row][col] = '!';

        // explore 4 directions
        bool found = searchNext(board, word, row - 1, col, index + 1, m, n) || // top
                     searchNext(board, word, row + 1, col, index + 1, m, n) || // bottom
                     searchNext(board, word, row, col - 1, index + 1, m, n) || // left
                     searchNext(board, word, row, col + 1, index + 1, m, n);   // right

        // undo marking
        board[row][col] = c;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) { // match first char
                    if (searchNext(board, word, i, j, 0, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};
