class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int> & nums,int k ,int idx,vector<int> & curr){
        if(k == 0){
            ans.push_back(curr);
            return;
        }
        if(idx >= nums.size()) return;

        //Pick
        curr.push_back(nums[idx]);
        f(nums,k-1,idx+1,curr);
        curr.pop_back();

        //not pick
        f(nums,k,idx+1,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);

        for(int i = 0;i<n;i++){
            nums[i] = i + 1;
        }
        vector<int> curr;
        int idx = 0;
        f(nums,k,idx,curr);
        return ans;
        
    }
};