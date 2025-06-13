class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses,0);
        adj.resize(numCourses);

        for(auto num : prerequisites){
            adj[num[1]].push_back(num[0]);
        }

        for(int i = 0;i<numCourses;i++){
            if(!dfs(i)) return false;
        }

        return true;

    }

    bool dfs(int node){
        if(visited[node] == 1) return false;
        if(visited[node] == 2) return true;
        visited[node] = 1;
        for(auto neig : adj[node]){
            if(!dfs(neig)) return false;
        }

        visited[node] = 2;

        return true;
    }
};