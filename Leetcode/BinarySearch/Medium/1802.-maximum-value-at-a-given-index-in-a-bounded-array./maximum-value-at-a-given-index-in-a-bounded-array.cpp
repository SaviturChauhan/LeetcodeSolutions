class Solution {
public:
    typedef long long ll;
    ll Formula(ll count,ll val){
        return ((count)*val) - (count * (count+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        ll left = 1;
        ll right = maxSum;
        ll mid;
        int ans = 0;

        while(left <= right){
            mid = left + (right -left)/2;

            ll lcount = min((ll)index,mid-1);
            ll lsum = Formula(lcount,mid);
            lsum += max((ll)0, index - (mid-1));

            ll rcount = min((ll)n-index-1,mid-1);
            ll rsum = Formula(rcount,mid);
            rsum += max((ll)0, n-index-1 - (mid-1));

            ll tsum = lsum + rsum + mid;

            if(tsum <= maxSum){
                ans = max((ll)ans,mid);
                left = mid+1;
            }else{
                right = mid-1;
            }
        } 
        return ans;
    }
};