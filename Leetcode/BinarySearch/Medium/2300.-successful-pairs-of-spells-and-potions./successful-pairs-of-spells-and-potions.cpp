class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());     
        for(int i = 0;i<n;i++){
            long long minpotion = ceil((1.0*success)/spells[i]);
            int l = 0;
            int r = m-1;
            if(minpotion > potions[m-1]){
                ans.push_back(0);
                continue;
            }

            while(l <= r){
                int mid = l + (r-l)/2;
                if(potions[mid] >= minpotion){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            ans.push_back(m-l);
        }
    return ans;
    }
};