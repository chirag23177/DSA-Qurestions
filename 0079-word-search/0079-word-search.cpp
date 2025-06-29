class Solution {
private:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (k == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            if(dfs(board, word, x, y, k + 1)){
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};