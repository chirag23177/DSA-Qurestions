class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[x][y] = true;
        
        for(int dir = 0; dir < 4; dir++){
            int new_x = x + dx[dir];
            int new_y = y + dy[dir];
            if(new_x >=0 && new_y >=0 && new_x < m && new_y < n && grid[new_x][new_y] == '1' && !visited[new_x][new_y]){
                visited[new_x][new_y] = true;
                dfs(grid, new_x, new_y, visited);
            }
        }


    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int island = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    island++;
                    dfs(grid, i,j,visited);
                }
            }
        }

        return island;
        
    }
};