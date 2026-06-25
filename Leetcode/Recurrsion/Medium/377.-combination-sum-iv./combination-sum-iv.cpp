class Solution {
public:
    int f(vector<int>& nums, int target,int idx, vector<vector<int>>& dp){
        if(target == 0){
            return 1;
        }
        if(target < 0 || idx >= nums.size()) return 0;
        if(dp[idx][target] != -1) return dp[idx][target];
        //pick
       int take =  f(nums,target-nums[idx],0,dp);
        //Not pick
        int reject = f(nums,target,idx+1,dp);
        return  dp[idx][target] = take + reject;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(201,vector<int>(10001,-1));
        int count = f(nums,target,0,dp);
        
        return count;
    }
};