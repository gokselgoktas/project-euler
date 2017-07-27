#include <bitset>
#include <iostream>

int main(int count, char *arguments[])
{
    std::bitset<1000000> sieve;
    sieve.set();

    for (unsigned i = 2; i * i < sieve.size(); ++i) {
        if (sieve[i] == true) {
            for (unsigned k = i << 1; k < sieve.size(); k += i) {
                sieve[k] = false;
            }
        }
    }

    unsigned r = 0;

    for (unsigned i = 2; i < sieve.size(); ++i) {
        if (sieve[i] == true) {
            if (++r == 10001) {
                std::cout << i << '\n';
                return 0;
            }
        }
    }

    return 1;
}
