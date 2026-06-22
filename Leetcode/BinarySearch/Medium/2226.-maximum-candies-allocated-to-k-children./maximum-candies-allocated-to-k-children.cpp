class Solution {
public:
    bool possible(vector<int>& candies, long long k,int mid){
        long long count = 0;
        for(int i = 0;i<candies.size();i++){
            if(mid != 0)count += candies[i]/mid;
            if(count >= k) return true;
            
        }
        return count >= k; 
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();

        int l = 1;
        int r = *max_element(candies.begin(),candies.end());
        int ans = 0;
        long long count = 0;
        for(int i = 0;i<candies.size();i++){
            count += candies[i];
        }
        if(count < k) return 0;


        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(candies,k,mid)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
    return ans;
    }
};