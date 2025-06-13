class Solution {
public:
    vector<int> visited;
    vector<vector<int>> adj;
    vector<int> result;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses,0);
        adj.resize(numCourses);

        for(auto num : prerequisites){
            adj[num[1]].push_back(num[0]);
        }

        for(int i = 0;i<numCourses;i++){
            if(!dfs(i)) return {};
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool dfs(int node){
        if(visited[node] == 1) return false;
        if(visited[node] == 2) return true;
        visited[node] = 1;
        for(auto neig : adj[node]){
            if(!dfs(neig)) return false;
        }

        visited[node] = 2;
        result.push_back(node);

        return true;
    }

};
