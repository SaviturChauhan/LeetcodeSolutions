class Solution {
public:
    typedef long long ll;
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ll count = 0;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        //here order is neglected as we add (i,j) or (j,i) it will be same

        for(int i =0;i<n;i++){
            //first idx less than or equal to lower - nums[i]
            int idx = lower_bound(nums.begin()+i+1,nums.end(),lower - nums[i]) - nums.begin();
            int x = idx-1-i;
             //first idx greater than upper - nums[i]
            idx = upper_bound(nums.begin()+i+1,nums.end(),upper - nums[i]) - nums.begin();
            int y = idx-1-i;
            count += (y-x);
        }
        return count;
    }
};