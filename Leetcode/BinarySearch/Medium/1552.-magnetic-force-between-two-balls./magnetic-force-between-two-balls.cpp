class Solution {
public:
    bool possible(vector<int>& position, int m,int mid){
        int prev = position[0];
        int count = 1;
        for(int i = 1;i<position.size();i++){
            int curr = position[i];
            if(curr - prev >= mid){
                count++;
                prev = curr;
            }

            if(count == m) break;
        }
        return count == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int l = 1;
        int r = position[n-1] - position[0];
        int ans = 0;


        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(position,m,mid)){
                ans = mid;
                l = mid +1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};