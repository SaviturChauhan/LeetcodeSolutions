class Solution {
public:
    typedef long long ll;

    bool possible(vector<int>& batteries,int n ,ll mid){
        ll target = mid * n;
        for(int i =0;i<batteries.size();i++){
            target -= min((ll)batteries[i],mid);
            if(target <= 0) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(batteries.begin(),batteries.end());
        ll sum = 0;
        for(auto & it : batteries){
            sum += it;
        }
        ll r = sum/n;
        ll ans = 0;

        while(l <= r){
            ll mid = l + (r-l)/2;
            if(possible(batteries,n,mid)){
              ans = mid;
              l = mid+1;
            }else{
              r= mid-1;
            }
        }
        return ans;
    }
};