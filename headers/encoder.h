#pragma once

std::vector <mpz_int> encode(std::vector <mpz_int> &message, mpz_int e, mpz_int m);
void encript(std::string input, std::string output, mpz_int e, mpz_int m);
void decript(std::string input, std::string output, mpz_int d, mpz_int m);
