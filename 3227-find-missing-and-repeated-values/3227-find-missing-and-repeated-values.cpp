class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n +1);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }

        int a,b;

        for(int i = 0; i<freq.size(); i++){
            if(freq[i] == 0) b = i;
            if(freq[i] == 2) a = i;
        }

        vector<int> res(2);
        res[0] = a;
        res[1] = b;

        return res;
    }
};