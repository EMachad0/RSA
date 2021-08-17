#pragma once

struct keys {
    mpz_int p, q, tot;
    mpz_int public_key;
    mpz_int public_key_mod;
    mpz_int private_key;
};

keys* key_generator(int bit_sz);
