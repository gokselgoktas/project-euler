#include <iostream>
#include <gmpxx.h>

int main(int count, char *arguments[])
{
        mpz_class factorial = 0;
        mpz_fac_ui(factorial.get_mpz_t(), 100);

        uint64_t sum = 0;

        for (auto i : factorial.get_str()) {
                sum += static_cast<uint64_t>(i - '0');
        }

        std::cout << sum << '\n';
        return 0;
}