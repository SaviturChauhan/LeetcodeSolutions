class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& candidates, int target,int idx,vector<int> &curr){
        if(idx == candidates.size()){
            if(target == 0) ans.push_back(curr);
            return;
        }
        if(target < 0) return;
        //Pick
        curr.push_back(candidates[idx]);
        f(candidates,target-candidates[idx],idx,curr);
        curr.pop_back();

        //Not Pick
       f(candidates,target,idx+1,curr);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        int idx = 0;
        f(candidates,target,idx,curr);
        return ans;
    }
};