class Solution {
public:
    bool isValid(vector<int>& nums, int mid_max, int n) {
        vector<long long> arr(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > mid_max)
                return false;
            long long buffer = mid_max - arr[i];
            arr[i + 1] = arr[i + 1] - buffer;
        }

        return arr[n - 1] <= mid_max;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isValid(nums, mid, n)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
   }
};