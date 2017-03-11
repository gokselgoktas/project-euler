#include <iostream>

int main(int count, char *arguments[])
{
        std::bitset<1999999> sieve;
        sieve.set();

        for (uint64_t i = 2; i * i < sieve.size(); ++i) {
                if (sieve[i] == true) {
                        for (uint64_t k = i << 1; k < sieve.size(); k += i) {
                                sieve[k] = false;
                        }
                }
        }

        uint64_t sum = 0;

        for (uint64_t i = 2; i < sieve.size(); ++i) {
                if (sieve[i] == true) {
                        sum += i;
                }
        }

        std::cout << sum << '\n';
}