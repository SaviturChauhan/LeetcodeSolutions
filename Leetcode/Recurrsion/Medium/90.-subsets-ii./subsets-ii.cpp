class Solution {
public:
    void f(vector<int>& nums, int idx, vector<int>& curr,set<vector<int>>& st) {
        if (idx == nums.size()) {
            st.insert(curr);
            return;
        }
        // Pick
        curr.push_back(nums[idx]);
        f(nums, idx + 1, curr,st);
        curr.pop_back();
        // Not Pick
        f(nums, idx + 1, curr,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        int idx = 0;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        f(nums, idx, curr,st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};