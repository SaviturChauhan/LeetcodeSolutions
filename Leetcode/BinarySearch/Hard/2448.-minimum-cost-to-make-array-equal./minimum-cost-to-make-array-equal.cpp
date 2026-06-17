class Solution {
public:
    typedef long long ll;
    ll f(vector<int>& nums,int mid, vector<int>& cost){
        int n = nums.size();
        ll val = 0;
        for(int i = 0;i<n;i++){
           val += ((ll)abs(mid-nums[i]) * cost[i]);
        }
        return val;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        ll l = *min_element(nums.begin(),nums.end());
        ll r = *max_element(nums.begin(),nums.end());
        ll ans = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;
            ll c1 = f(nums,mid,cost);
            ll c2 = f(nums,mid+1,cost);

            ans = min(c1,c2);

            if(c2 > c1) r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};