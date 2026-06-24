class Solution {
public:
    typedef long long ll;
    double power(double x, ll n){
       if(n == 0) return 1.0;
       if(n == 1) return x;
       if(n%2 == 0) return power(x*x,n/2);
       return x * power(x,n-1);
    }
    double myPow(double x, int n) {
        ll num = n;
        if (num < 0) {
            return (1.0 / power(x, -1 * num));
        }
        return power(x, num);
    }
};