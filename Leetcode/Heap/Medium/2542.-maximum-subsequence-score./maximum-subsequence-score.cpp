class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int n = nums1.size();
        vector<pair<int, int>> vec(n);

        for (int i = 0; i < n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        auto lambda = [&](auto& p1, auto& p2) {
            return p1.second > p2.second;
        }; 
        sort(vec.begin(), vec.end(), lambda);

        long long ksum = 0;

        for (int i = 0; i <= k - 1; i++) {
            ksum += vec[i].first;
            pq.push(vec[i].first);
        }

        ans = ksum * vec[k-1].second;

        for(int i = k;i<n;i++){
            ksum += vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);
            ans = max(ans,ksum * vec[i].second);
        }
        return ans;
    }
};