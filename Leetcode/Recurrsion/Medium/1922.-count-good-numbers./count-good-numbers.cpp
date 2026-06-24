}

    int countGoodNumbers(long long n) {
        ll even = (n + 1) / 2;
        ll odd = n / 2;
        return (power(5, even) * power(4, odd)) % MOD;
    }
};
        return (x * power(x, n - 1)) % MOD;
            return power((x * x) % MOD, n / 2);
        if (n % 2 == 0)