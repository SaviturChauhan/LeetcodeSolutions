class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& nums,int idx,vector<int>& curr){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        //Pick
        curr.push_back(nums[idx]);
        f(nums,idx+1,curr);
        curr.pop_back();
        //Not Pick
        f(nums,idx+1,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        int idx = 0;
        f(nums,idx,curr);
        return ans;
    }
};