class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<p, vector<p>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum,{i,j}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }else{
                    break;
                }
            }
        }

      
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back({nums1[i],nums2[j]});     
        }
        return ans;
    }
};