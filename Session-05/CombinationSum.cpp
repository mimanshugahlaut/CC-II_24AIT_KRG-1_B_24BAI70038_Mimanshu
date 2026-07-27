class Solution {
public:
    vector<vector<int>> result;
    vector<int>current;

    void solve(vector<int> &candidates, int target, int index) {
        if(target == 0) {
            result.push_back(current);
            return;
        }
        if(target < 0) return;

        for(int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return result;
    }
};
