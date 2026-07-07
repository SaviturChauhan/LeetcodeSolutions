class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        ll x = 0;
        ll sum = 0;

        while(n > 0){
            int r = n % 10;
            sum += r;
            if(r != 0) x = x * 10 + r;
            n /= 10;
        }
        ll ans = 0;
        while(x>0){
            ll r = x % 10;
            ans = ans * 10 + r;
            x = x/10;
        }
        return ans*sum;
    }
};