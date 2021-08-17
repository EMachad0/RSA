# include <iostream>
# include <fstream>
# include <vector>
# include <boost/multiprecision/gmp.hpp>
using namespace boost::multiprecision;
# include "../headers/exp_mod.h"


std::vector <mpz_int> encode(std::vector <mpz_int> &message, mpz_int e, mpz_int m) {
    std::vector <mpz_int> encoded;
    for (auto i : message) {
        mpz_int enc = exp_mod(i, e, m);
        encoded.push_back(enc);
    }
    return encoded;
}

void encript(std::string input, std::string output, mpz_int e, mpz_int m) {
    std::ifstream input_file(input);
    std::ofstream output_file(output);

    char c = 0;
    std::vector <mpz_int> message;
    while (input_file.get(c)) message.push_back(mpz_int(c));
    std::vector <mpz_int> o_message = encode(message, e, m);
    for (auto i : o_message) output_file << i << " ";
}


void decript(std::string input, std::string output, mpz_int d, mpz_int m) {
    std::ifstream input_file(input);
    std::ofstream output_file(output);

    mpz_int c = 0;
    std::vector <mpz_int> message;
    while (input_file >> c) message.push_back(c);
    std::vector <mpz_int> o_message = encode(message, d, m);
    for (auto i : o_message) output_file << (char) i;
}