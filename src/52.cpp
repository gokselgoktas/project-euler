#include <iostream>

#include <limits>
#include <bitset>

std::bitset<10> split(unsigned number) noexcept
{
        std::bitset<10> result;

        while (number > 0) {
                unsigned digit = number % 10;
                number /= 10;

                result[digit] = true;
        }

        return result;
}

template <size_t size>
bool isPermutation(std::bitset<size> const &first, std::bitset<size> const &second) noexcept
{
        for (size_t i = 0; i < second.size(); ++i) {
                if (first[i] != second[i]) {
                        return false;
                }
        }

        return true;
}

bool isPermutation(unsigned first, unsigned second) noexcept
{
        std::bitset<10> i = split(first);
        std::bitset<10> k = split(second);

        return isPermutation(i, k);
}

int main(int count, char *arguments[])
{
        for (unsigned i = 1; i < std::numeric_limits<unsigned>::max(); ++i) {
                unsigned k = 2;

                for (; k < 7; ++k) {
                        if (isPermutation(i, i * k) == false) {
                                break;
                        }
                }

                if (k == 7) {
                        std::cout << i << '\n';
                        return 0;
                }
        }

        return 0;
}