class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();

        for (int i = 0; i < rows; i++) {
            vector<int> arr(10, 0);
            for (int j = 0; j < columns; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    arr[val]++;
                    if (arr[val] > 1) {
                        return false;
                    }
                }
            }
        }

        for (int j = 0; j < columns; j++) {
            vector<int> arr2(10, 0);
            for (int i = 0; i < rows; i++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    arr2[val]++;
                    if (arr2[val] > 1) {
                        return false;
                    }
                }
            }
        }

        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                vector<int> freq(10, 0);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int row = boxRow * 3 + i;
                        int col = boxCol * 3 + j;
                        if (board[row][col] != '.') {
                            int val = board[row][col] - '0';
                            freq[val]++;
                            if (freq[val] > 1)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
