class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // found a valid combination
            return;
        }
        if (target < 0) return; // overshoot, stop

        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);             // choose
            backtrack(candidates, target - candidates[i], // explore
                      i, current, result); 
            current.pop_back();                            // undo (backtrack)
        }
    }
};