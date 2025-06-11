class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        visited[x][y] = true;
        int area = 1;
        for(int dir = 0; dir < 4; dir++){
            int new_x = x + dx[dir];
            int new_y = y + dy[dir];
            if(new_x >=0 && new_y >=0 && new_x < m && new_y < n && grid[new_x][new_y] == 1 && !visited[new_x][new_y]){
                area += dfs(grid, new_x, new_y, visited);
            }
        }

        return area;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxarea = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int area = dfs(grid, i,j,visited) ;
                    maxarea = max(area, maxarea);
                }
            }
        }

        return maxarea;
    }
};