class Solution {
public:
    using p = pair<char, int>;

    struct lambda {
        bool operator()(const p &p1, const p &p2) const {
            return p1.second < p2.second;   // Max heap by frequency
        }
    };

    string frequencySort(string s) {
        string ans = "";

        priority_queue<p, vector<p>, lambda> pq;
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        for (auto &it : mp) {
            pq.push({it.first, it.second});
        }

        while (!pq.empty()) {
            p a = pq.top();
            pq.pop();

            ans += string(a.second, a.first);
        }

        return ans;
    }
};