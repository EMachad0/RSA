# include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;


mpz_int extended_gcd(mpz_int a, mpz_int b, mpz_int& x, mpz_int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    mpz_int x1, y1;
    mpz_int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

mpz_int inv_mod(mpz_int a, mpz_int m) {
    mpz_int x, y;
    mpz_int g = extended_gcd(a, m, x, y);
    if (g != 1) return 0;
    else return (x % m + m) % m;
}