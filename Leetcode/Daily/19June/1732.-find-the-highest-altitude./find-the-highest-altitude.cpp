class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> pref(n+1);
        pref[0] = 0;
        int ans = 0;

        for(int i =1;i<n+1;i++){
            pref[i] = pref[i-1] + gain[i-1];
            ans = max(ans,pref[i]);
        }
        return ans;
    }
};