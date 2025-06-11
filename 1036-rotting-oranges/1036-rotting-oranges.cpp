class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int minute = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dx[4] = {-1,1,0,0};
            int dy[4] = {0,0,-1,1};
            for(int dir = 0; dir<4; dir++){
                int nx = x+dx[dir];
                int ny = y+dy[dir];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny] == 1){
                    // minute++;
                    // grid[nx][ny] = 2;
                    grid[nx][ny] = grid[x][y] +1;
                    q.push({nx,ny});
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
                else{
                    minute = max(minute, grid[i][j]);
                }
            }
        }
        minute = minute-2;

        return(max(0,minute));
    }
};