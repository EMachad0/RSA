# include <stdlib.h>
# include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;
# include "../headers/key_generator.h"
# include "../headers/number_generator.h"
# include "../headers/inv_mod.h"


keys* key_generator(int bit_sz) {
    keys* ks = new keys;
    set_bit_sz(bit_sz);
    ks->p = get_prime();
    ks->q = get_prime();
    ks->tot = (ks->p - 1) * (ks->q - 1);
    ks->public_key_mod = ks->p * ks->q;
    do {
        ks->public_key = get_prime();
    } while(ks->public_key >= ks->tot);
    ks->private_key = inv_mod(ks->public_key, ks->tot);
    return ks;
}
