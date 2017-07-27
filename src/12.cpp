#include <iostream>

#include <cmath>
#include <limits>

static constexpr unsigned getTriangleNumber(unsigned i) noexcept
{
        return ((i * (i + 1)) >> 1);
}

static unsigned getDivisorCount(unsigned number) noexcept
{
        unsigned count = 0;
        unsigned root = static_cast<unsigned>(std::sqrt(number));

        for (unsigned i = 1; i < root; ++i) {
                if (number % i == 0) {
                        count += 2;
                }
        }

        return count;
}

int main(int count, char *arguments[])
{
        for (unsigned i = 7; i < std::numeric_limits<unsigned>::max(); ++i) {
                unsigned number = getTriangleNumber(i);

                if (getDivisorCount(number) > 500) {
                        std::cout << number << '\n';
                        return 0;
                }
        }

        return 1;
}