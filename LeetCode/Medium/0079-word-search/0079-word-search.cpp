class Solution {
public:
    int n, m;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool valid(vector<vector<char>>& board, string& word, int i, int k, int j) {
        if (i == word.size()) {
            return true;
        }

        if (k < 0 || j < 0 || k >= n || j >= m || board[k][j] == '$') {
            return false;
        }

        if (word[i] != board[k][j]) {
            return false;
        }

        char temp = board[k][j];
        board[k][j] = '$';

        for (int l = 0; l < 4; l++) {
            int newk = k + dir[l][0];
            int newj = j + dir[l][1];

            if (valid(board, word, i + 1, newk, newj)) {
                board[k][j] = temp;   // restore before returning
                return true;
            }
        }

        board[k][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && valid(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};