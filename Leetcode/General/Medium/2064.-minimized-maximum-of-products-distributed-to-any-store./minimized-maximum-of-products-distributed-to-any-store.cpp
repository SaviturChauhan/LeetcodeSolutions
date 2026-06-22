class Solution {
public:
    bool distribution(int n, vector<int>& quantities,int mid){
        for(int i =0;i<quantities.size();i++){
            n -= ceil(1.0*quantities[i]/mid);
            if(n < 0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int l = 1;
        int r = *max_element(quantities.begin(),quantities.end());
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(distribution(n,quantities,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};