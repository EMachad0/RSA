# include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;


mpz_int exp_mod(mpz_int base, mpz_int exp, mpz_int mod) {
    mpz_int b = base, res = 1;
    while(exp){
        if(exp & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return res;
}
