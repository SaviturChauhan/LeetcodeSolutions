class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candidates, int target, int idx, vector<int>& curr) {
        if (target < 0)
            return;

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            f(candidates, target - candidates[i], i + 1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        int idx = 0; 
        f(candidates, target, idx, curr);
        return ans;
    }
};