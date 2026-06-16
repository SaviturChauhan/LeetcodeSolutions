class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid;
        
        while(l <= r){
           mid = l + (r-l)/2;
           int elleft = nums[mid] - (mid+1);
           if(elleft < k) l = mid +1;
           else r = mid-1;
        }

        return l+k;

        
    }
};