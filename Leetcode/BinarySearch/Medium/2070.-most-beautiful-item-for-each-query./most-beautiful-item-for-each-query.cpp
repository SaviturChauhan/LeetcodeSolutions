class Solution {
public:
    typedef pair<int, int> p;
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        vector<p> arr;

        int m = items.size();
        for (auto& it : items) {
            int price = it[0];
            int beauty = it[1];
            arr.push_back({price, beauty});
        }

        sort(arr.begin(), arr.end());
        vector<int> maxbeauty(m);
         maxbeauty[0] = arr[0].second;
        for (int i = 1; i < m; i++) {
            maxbeauty[i] = max(maxbeauty[i - 1], arr[i].second);
        }

        for (int i = 0; i < n; i++) {
            int price = queries[i];
            int l = 0;
            int r = m - 1;
            int idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid].first <= price) {
                    idx = mid;
                    l = mid + 1;
                } else {
                   r = mid-1;
                }
            }
            ans[i] = idx == -1 ? 0 : maxbeauty[idx];
        }
        return ans;
    }
};