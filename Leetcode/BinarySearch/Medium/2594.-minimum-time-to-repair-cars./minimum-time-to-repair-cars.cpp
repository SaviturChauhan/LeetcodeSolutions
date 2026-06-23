class Solution {
public:

    typedef long long ll;
    bool cost(vector<int>& ranks, int cars,ll mid){
        ll curr = 0;
        for(int i =0;i<ranks.size();i++){
            curr += (long long)sqrt((double)mid / ranks[i]);
            if(curr > cars) return true;
        }
        return curr >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll l = 0;
        ll r = *min_element(ranks.begin(),ranks.end()) * pow(cars,2);
        ll ans = 0;

        while(l <= r){
            ll mid = l + (r-l)/2;
            if(cost(ranks,cars,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};