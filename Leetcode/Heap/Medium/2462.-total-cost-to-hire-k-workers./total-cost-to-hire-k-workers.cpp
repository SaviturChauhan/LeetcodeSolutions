class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int hired = 0;
        ll ans = 0;

        int i = 0, j = n - 1;

        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        while (hired < k) {
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i]);
                i++;
            }
            while (pq2.size() < candidates && j >= i) {
                pq2.push(costs[j]);
                j--;
            }
            int minpq1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int minpq2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (minpq1 <= minpq2) {
                ans += pq1.top();
                pq1.pop();
            } else {
                ans += pq2.top();
                pq2.pop();
            }
            hired++;
        }

        return ans;
    }
};