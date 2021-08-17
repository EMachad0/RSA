# include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;

mpz_int pollard_rho(mpz_int value) {
    mpz_int i = 0, k = 2, d;
    mpz_int x = 3, y = 3;
    
    while(++i) {
        x = (x * x) % value;
        x += value - 1;
        x %= value;
        d = gcd(abs(x - y), value);
        if (d != 1 && d != value) return d;
        if (i == k) {
            y = x;
            k <<= 1;
        }
    }
    return -1;
}
