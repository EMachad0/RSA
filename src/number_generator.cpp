# include <boost/multiprecision/gmp.hpp>
# include <boost/random.hpp>
using namespace boost::multiprecision;
using namespace boost::random;
# include "../headers/primality.h"


mpz_int lower_bound, upper_bound;


mpz_int get_random_test_number() {
    uniform_int_distribution<mpz_int> gen(lower_bound, upper_bound);
    mt19937 mt(clock());
    return gen(mt) | 1;
}


mpz_int get_prime() {
    uniform_int_distribution<mpz_int> gen(lower_bound, upper_bound);
    mt19937 mt(clock());

    mpz_int prime;
    do {
        prime = gen(mt) | 1;
    } while (!is_prime(prime));
    return prime;
}


void set_bit_sz(int bit_sz) {
    lower_bound = mpz_int(1) << (bit_sz - 1);
    upper_bound = (mpz_int(1) << bit_sz) - 1;
}