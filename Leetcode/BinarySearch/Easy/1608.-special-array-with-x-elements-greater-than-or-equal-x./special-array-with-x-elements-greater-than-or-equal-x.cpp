class Solution {
public:
    int special(vector<int>& nums,int mid){
        int count = 0;
        for(int i = 0;i<nums.size();i++){
           if(nums[i] >= mid ) count++;
        }
        return count;
    }
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = *max_element(nums.begin(),nums.end());
        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            int val = special(nums,mid);
            if( val == mid) return mid;
            else if(val > mid){
                l = mid+1; 
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
};