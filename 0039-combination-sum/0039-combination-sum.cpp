class Solution {
private:
    vector<vector<int>> result;
    vector<int> sums;

    void dfs(vector<int>& candidates, int target, int i, int sum){
        if(i >= candidates.size() || sum>target){
            return;
        }

        if(sum == target){
            result.push_back(sums);
            return;
        }

        sums.push_back(candidates[i]);
        dfs(candidates, target, i, sum+candidates[i]);

        sums.pop_back();
        dfs(candidates, target, i+1, sum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target, 0, 0);

        return result;
    }
};