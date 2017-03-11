#include <iostream>

static constexpr unsigned getSequenceLength(unsigned number) noexcept
{
        unsigned length = 0;

        while (number != 1) {
                if ((number & 1) == 0) {
                        number >>= 1;
                } else {
                        number = 3 * number + 1;
                }

                ++length;
        }

        return length;
}

int main(int count, char *arguments[])
{
        unsigned number = 999999;
        unsigned maximum = 0;

        for (unsigned i = 999999; i > 0; --i) {
                unsigned length = getSequenceLength(i);

                if (length > maximum) {
                        maximum = length;
                        number = i;
                }
        }

        std::cout << number << '\n';
        return 0;
}