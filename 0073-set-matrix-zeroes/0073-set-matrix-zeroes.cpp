class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row0;
        set<int> col0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<columns; j++){
                if(matrix[i][j] == 0){
                    row0.insert(i);
                    col0.insert(j);
                }
            }
        }

        while(!row0.empty()){
            for(int i = 0; i<rows; i++){
                if(i == *row0.begin()){
                    for(int j = 0;j<columns; j++){
                        matrix[i][j] = 0;
                    }
                    row0.erase(row0.begin());
                }
            }
        }

        while(!col0.empty()){
            for(int j = 0; j<columns; j++){
                if(j == *col0.begin()){
                    for(int i = 0;i<rows; i++){
                        matrix[i][j] = 0;
                    }
                    col0.erase(col0.begin());
                }
            }
        }
    }
};