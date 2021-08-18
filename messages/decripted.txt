#include <iostream>
#include <chrono>
#include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;
#include "headers/key_generator.h"
#include "headers/encoder.h"
#include "headers/pollard_rho.h"


int main(int argc, char** argv) {
    using namespace std::chrono;

    bool breaker = false, timer = false, logger = false;
    int prime_bit_sz = 64;
    char *path = NULL;

    std::chrono::steady_clock::time_point begin, end;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) logger = true;
        else if (strcmp(argv[i], "-b") == 0) breaker = true;
        else if (strcmp(argv[i], "-t") == 0) timer = true;
        else if (strcmp(argv[i], "--sz") == 0) prime_bit_sz = atoi(argv[++i]);
        else path = argv[i];
    }

    begin = std::chrono::steady_clock::now();
    keys* ks = key_generator(prime_bit_sz/2);
    end = std::chrono::steady_clock::now();
    if (timer) std::cout << duration_cast<milliseconds>(end - begin).count() << " ";

    if (logger) {
        std::cout << "----------------- keys ----------------" << std::endl;
        std::cout << "p:               " << ks->p              << std::endl;
        std::cout << "q:               " << ks->q              << std::endl;
        std::cout << "tot:             " << ks->tot            << std::endl;
        std::cout << "public key:      " << ks->public_key     << std::endl;
        std::cout << "public key mod:  " << ks->public_key_mod << std::endl;
        std::cout << "private key mod: " << ks->private_key    << std::endl;
    }

    if (path != NULL) {
        begin = std::chrono::steady_clock::now();
        encript(std::string(path), "messages/encripted.txt", ks->public_key, ks->public_key_mod);
        end = std::chrono::steady_clock::now();
        if (timer) std::cout << duration_cast<milliseconds>(end - begin).count() << " ";

        begin = std::chrono::steady_clock::now();
        decript("messages/encripted.txt", "messages/decripted.txt", ks->private_key, ks->public_key_mod);
        end = std::chrono::steady_clock::now();
        if (timer) std::cout << duration_cast<milliseconds>(end - begin).count() << " ";
    }

    if (breaker) {
        begin = std::chrono::steady_clock::now();
        mpz_int p = pollard_rho(ks->public_key_mod);
        mpz_int q = ks->public_key_mod / p;
        end = std::chrono::steady_clock::now();
        if (logger) std::cout << "--- breaker ---" << std::endl;
        if (timer) std::cout << duration_cast<milliseconds>(end - begin).count() << " ";
        if (logger) {
            std::cout << "p: " << p << std::endl;
            std::cout << "q: " << q << std::endl;
        }
    }

    if (timer) std::cout << std::endl;
}