class Solution {
public: 
    bool possible(vector<int>& bloomDay, int m, int k,int mid){
        int count = 0;
        int curr = 0;

        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                curr++;
            }else{
                curr = 0;
            }
            if(curr == k){
                count++;
                curr = 0;
            }
        }
        return count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long prod = (long long)m * (long long)k ;
        if(prod > (long long)n) return -1;

        int l = 0;
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(bloomDay,m,k,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }

        }
        return ans;
    }
};