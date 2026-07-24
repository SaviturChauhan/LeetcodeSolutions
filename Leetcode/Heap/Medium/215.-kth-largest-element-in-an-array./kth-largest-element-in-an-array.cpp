class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int i = 0;

        while(pq.size() <= k && i < n){
            if(pq.size() < k) pq.push(nums[i]);
            else if(nums[i] > pq.top()) {
                pq.push(nums[i]);
                pq.pop();
            }else{
                continue;
            }
            i++;
        }
        return pq.top();
    }
};