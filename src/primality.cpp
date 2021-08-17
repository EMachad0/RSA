# include <boost/multiprecision/gmp.hpp>
# include <boost/random.hpp>
using namespace boost::multiprecision;
# include "../headers/exp_mod.h"
# include "../headers/number_generator.h"


const int RANDOM_TEST_COUNT = 25;


bool is_composite(mpz_int n, mpz_int a, mpz_int d, int s) {
    mpz_int x = exp_mod(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}


bool is_prime(mpz_int n) { // miller rabin
    if (n < 2) return false;
    int r = 0;
    mpz_int d = n - 1;
    while ((d & 1) == 0) d >>= 1, ++r;
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (is_composite(n, a, d, r)) return false;
    }
    for (int i = 0; i < RANDOM_TEST_COUNT; i++) {
        mpz_int a = get_random_test_number();
        if (is_composite(n, a, d, r)) return false;
    }
    return true;
}
