#include <iostream>
#include <fstream>
#include <vector>

int main(int count, char *arguments[])
{
        if (count == 1) {
                return 1;
        }

        std::ifstream input(arguments[1]);

        if (input.fail() == true) {
                return 1;
        }

        std::vector<unsigned> numbers;
        std::istream_iterator<unsigned> iterator(input);

        std::copy(iterator, std::istream_iterator<unsigned>(),
                std::back_inserter(numbers));

        for (ssize_t row = 98; row > -1; --row) {
                size_t const elementCount = row + 1;
                size_t const offset = (row * elementCount) >> 1;

                auto i = numbers.begin() + offset;
                auto k = i + elementCount;

                auto const end = k;

                for (; i != end; ++i) {
                        *i = std::max(*i + *k, *i + *(k + 1));
                        ++k;
                }
        }

        std::cout << numbers[0] << '\n';
        return 0;
}