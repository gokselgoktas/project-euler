#include <cmath>
#include <cstdint>
#include <iostream>

static uint64_t rotate(uint64_t number, size_t length) noexcept
{
    constexpr uint64_t lookup[] = {1, 10, 100, 1000, 10000, 100000};

    return ((number / 10) + (number % 10) * lookup[length - 1]);
}

int main(int count, char *arguments[])
{
    std::bitset<999999> sieve;
    sieve.set();

    for (uint64_t i = 2; i * i < sieve.size(); ++i) {
        if (sieve[i] == true) {
            for (uint64_t k = i << 1; k < sieve.size(); k += i) {
                sieve[k] = false;
            }
        }
    }

    uint64_t result = 1;

    for (uint64_t i = 3; i < sieve.size(); i += 2) {
        if (sieve[i] == true) {
            size_t length = static_cast<size_t>(std::ceil(std::log10(i)));

            uint64_t k = rotate(i, length);

            while (k != i) {
                if (sieve[k] == false) {
                    break;
                }

                k = rotate(k, length);
            }

            if (k == i) {
                ++result;
            }
        }
    }

    std::cout << result << '\n';
    return 0;
}