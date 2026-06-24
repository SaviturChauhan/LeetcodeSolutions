class Solution {
public:
    typedef long long ll;
    const int INT_MAX_VAL = pow(2, 31) - 1;
    const int INT_MIN_VAL = -1 * pow(2, 31);
    int helper(string s, int idx, ll num, int sign) {
        // out of bound or not a digit
        if (idx >= s.size() || !isdigit(s[idx])) {
            return (int)(num * sign);
        }
        num = num * 10 + (s[idx] - '0');
        if (num * sign <= INT_MIN_VAL)
            return INT_MIN_VAL;
        if (num * sign >= INT_MAX_VAL)
            return INT_MAX_VAL;

        return helper(s, idx + 1, num, sign);
    }
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        // Skip the whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        // Determine the sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        ll num = 0;

        return helper(s, i, num, sign);
    }
};