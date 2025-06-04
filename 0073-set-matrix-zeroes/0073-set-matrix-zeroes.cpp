class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: Check if first row or column needs to be zero
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) firstColZero = true;
        }
        for (int j = 0; j < cols; ++j) {
            if (matrix[0][j] == 0) firstRowZero = true;
        }

        // Step 2: Use first row and column as markers
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3: Zero rows and columns based on markers
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < cols; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4: Handle first row and column separately
        if (firstRowZero) {
            for (int j = 0; j < cols; ++j) matrix[0][j] = 0;
        }

        if (firstColZero) {
            for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
        }
    }
};
