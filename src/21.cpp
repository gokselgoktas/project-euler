#include <iostream>

#include <cmath>
#include <array>
#include <unordered_set>

static unsigned getSumOfDivisors(unsigned number) noexcept
{
        unsigned sum = 1;
        unsigned root = static_cast<unsigned>(std::sqrt(number));

        for (unsigned i = 2; i <= root; ++i) {
                if (number % i == 0) {
                        sum += i;

                        unsigned const counterpart = number / i;
                        if (counterpart != i) {
                                sum += counterpart;
                        }
                }
        }

        return sum;
}

int main(int count, char *arguments[])
{
        std::array<unsigned, 10000> array { { 0, 1 } };

        for (auto i = array.begin() + 2; i != array.end(); ++i) {
                *i = getSumOfDivisors(std::distance(array.begin(), i));
        }

        std::unordered_set<unsigned> amicableNumbers;

        for (auto i : array) {
                if (i > array.size() || array[i] > array.size()) {
                        continue;
                }

                if (i != array[i] && i == array[array[i]]) {
                        amicableNumbers.insert(i);
                        amicableNumbers.insert(array[i]);
                }
        }

        unsigned sum = 0;

        for (auto i : amicableNumbers) {
                sum += i;
        }

        std::cout << sum << '\n';
        return 0;
}