class Solution {
public:
    typedef pair<int, int> p;
    typedef long long ll;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end()); //{start_time , processtime , idx}
        priority_queue<p, vector<p>, greater<p>> pq;

        ll curr = 0;
        int idx = 0;

        while (idx < n || !pq.empty()) {
            if (pq.empty() && curr < tasks[idx][0]) {
                curr = tasks[idx][0];
            }

            while (idx < n && tasks[idx][0] <= curr) {
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }

            p ontop = pq.top();
            pq.pop();

            curr += ontop.first;
            ans.push_back(ontop.second);
        }

        return ans;
    }
};