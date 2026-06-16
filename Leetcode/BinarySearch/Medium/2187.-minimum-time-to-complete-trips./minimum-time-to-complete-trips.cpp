class Solution {
public:
    using ll = long long;

    bool possible(vector<int>& time, ll t, int totalTrips) {
        ll trips = 0;

        for (int x : time) {
            trips += t / x;
            if (trips >= totalTrips) return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1;
        ll r = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while (l < r) {
            ll mid = l + (r - l) / 2;

            if (possible(time, mid, totalTrips))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};