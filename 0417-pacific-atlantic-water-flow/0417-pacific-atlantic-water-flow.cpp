class Solution {
public:
    int n,m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        if(n == 1 && m ==1){
            return {{0,0}};
        }

        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));

        queue<pair<int, int>> pq, aq;

        for(int i = 0; i<n; i++){
            pq.push({i,0});
            aq.push({i,m-1});
            pacific[i][0]  = true;
            atlantic[i][m-1]  = true;
        }

        for(int j = 0; j<m; j++){
            pq.push({0,j});
            aq.push({n-1,j});
            pacific[0][j]  = true;
            atlantic[n-1][j]  = true;
        }

        bfs(heights, pacific, pq);
        bfs(heights, atlantic, aq);

        vector<vector<int>> result;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;

    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int,int>> q){
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int dir = 0; dir<4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx>=0 && ny>=0 && nx<n && ny<m && heights[nx][ny] >= heights[x][y] && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }

            }

        }
    }
};