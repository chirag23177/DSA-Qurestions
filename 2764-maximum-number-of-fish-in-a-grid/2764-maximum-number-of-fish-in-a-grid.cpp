// class Solution {
// public:
//     #define pip pair<int,pair<int,int>>
//     int findMaxFish(vector<vector<int>>& grid) {
//         priority_queue<pair<int, pair<int, int>>> pq;
//         int vis[grid.size()*grid[1].size()];
//         for(int i=0;i<grid.size()*grid[1].size();i++){
//             vis[i]=0;
//         }
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[i].size();j++){
//                 if(grid[i][j]!=0){
//                     pq.push({grid[i][j],{i,j}});
//                 }
//             }
//         }
//         int finalans =0;
//         while(!pq.empty()){
//             int ans=0;
//             queue<pair<int,pair<int,int>>> temp;
//             pip x = pq.top();
//             pq.pop();
            
//             int i = x.second.first;
//             int j = x.second.second;
//             if(vis[i * grid[0].size() + j]==0){
//             ans=ans+grid[i][j];
//             if(i!=0){
//                 if(vis[i-1 * grid[0].size() + j]==0&&grid[i-1][j]!=0){
//                     temp.push({grid[i-1][j],{i-1,j}});
//                 }
//             }
//             if(i!=grid.size()-1&&grid[i+1][j]!=0){
//                 if(vis[i+1 * grid[0].size() + j]==0){
//                     temp.push({grid[i+1][j],{i+1,j}});
//                 }
//             }
//             if(j!=0){
//                 if(vis[i * grid[0].size() + j-1]==0&&grid[i][j-1]!=0){
//                     temp.push({grid[i][j-1],{i,j-1}});
//                 }
//             }
//             if(j!=grid[1].size()-1){
//                 if(vis[i * grid[0].size() + j+1]==0&&grid[i][j+1]!=0){
//                     temp.push({grid[i][j+1],{i,j+1}});
//                 }
//             }
//             while(!temp.empty()){
//                 pip v = temp.front();
//                 temp.pop();
//                 int i = v.second.first;
//                 int j = v.second.second;
//                 ans=ans+grid[i][j];
//                 if(vis[i*j]==0){
//                 if(i!=0){
//                     if(vis[i-1 * grid[0].size() + j]==0&&grid[i-1][j]!=0){
//                         temp.push({grid[i-1][j],{i-1,j}});
//                     }
//                 }
//                 if(i!=grid.size()-1){
//                     if(vis[i+1 * grid[0].size() + j]==0&&grid[i+1][j]!=0){
//                         temp.push({grid[i+1][j],{i+1,j}});
//                     }
//                 }
//                 if(j!=0){
//                     if(vis[i * grid[0].size() + j-1]==0&&grid[i][j-1]!=0){
//                         temp.push({grid[i][j-1],{i,j-1}});
//                     }
//                 }
//                 if(j!=grid[1].size()-1){
//                     if(vis[i * grid[0].size() + j+1]==0&&grid[i][j+1]!=0){
//                         temp.push({grid[i][j+1],{i,j+1}});
//                     }
//                 }
//                 }
//             }
//             if(finalans<ans){
//                 finalans=ans;
//             }
//             }
//         }
//         return finalans;
//     }
// };

class Solution {
public:
    #define pip pair<int, pair<int, int>>
    int findMaxFish(vector<vector<int>>& grid) {
        priority_queue<pip> pq;
        int rows = grid.size();
        int cols = grid[0].size();

        // Create a visited array
        vector<int> vis(rows * cols, 0);

        // Push all non-zero cells into the priority queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 0) {
                    pq.push({grid[i][j], {i, j}});
                }
            }
        }

        int finalans = 0;

        // Process the priority queue
        while (!pq.empty()) {
            int ans = 0;
            queue<pip> temp;
            pip x = pq.top();
            pq.pop();

            int i = x.second.first;
            int j = x.second.second;

            int idx = i * cols + j;  // Calculate 1D index for the visited array

            // If this cell has not been visited
            if (vis[idx] == 0) {
                ans += grid[i][j];
                vis[idx] = 1;  // Mark as visited

                // Add valid neighbors to the temp queue
                if (i > 0 && vis[(i - 1) * cols + j] == 0 && grid[i - 1][j] != 0) {
                    temp.push({grid[i - 1][j], {i - 1, j}});
                }
                if (i < rows - 1 && vis[(i + 1) * cols + j] == 0 && grid[i + 1][j] != 0) {
                    temp.push({grid[i + 1][j], {i + 1, j}});
                }
                if (j > 0 && vis[i * cols + (j - 1)] == 0 && grid[i][j - 1] != 0) {
                    temp.push({grid[i][j - 1], {i, j - 1}});
                }
                if (j < cols - 1 && vis[i * cols + (j + 1)] == 0 && grid[i][j + 1] != 0) {
                    temp.push({grid[i][j + 1], {i, j + 1}});
                }

                // Process all neighbors in the temp queue
                while (!temp.empty()) {
                    pip v = temp.front();
                    temp.pop();

                    int ni = v.second.first;
                    int nj = v.second.second;
                    int nidx = ni * cols + nj;  // 1D index for neighbor

                    // If neighbor has not been visited
                    if (vis[nidx] == 0) {
                        ans += grid[ni][nj];
                        vis[nidx] = 1;  // Mark neighbor as visited

                        // Add valid neighbors of this neighbor
                        if (ni > 0 && vis[(ni - 1) * cols + nj] == 0 && grid[ni - 1][nj] != 0) {
                            temp.push({grid[ni - 1][nj], {ni - 1, nj}});
                        }
                        if (ni < rows - 1 && vis[(ni + 1) * cols + nj] == 0 && grid[ni + 1][nj] != 0) {
                            temp.push({grid[ni + 1][nj], {ni + 1, nj}});
                        }
                        if (nj > 0 && vis[ni * cols + (nj - 1)] == 0 && grid[ni][nj - 1] != 0) {
                            temp.push({grid[ni][nj - 1], {ni, nj - 1}});
                        }
                        if (nj < cols - 1 && vis[ni * cols + (nj + 1)] == 0 && grid[ni][nj + 1] != 0) {
                            temp.push({grid[ni][nj + 1], {ni, nj + 1}});
                        }
                    }
                }

                // Update the final answer
                finalans = max(finalans, ans);
            }
        }

        return finalans;
    }
};
