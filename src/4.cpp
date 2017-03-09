#include <iostream>

static bool isPalindrome(unsigned number) noexcept
{
        unsigned helper = number;
        unsigned reverse = 0;

        while (helper > 0) {
                unsigned digit = helper % 10;
                helper /= 10;

                reverse *= 10;
                reverse += digit;
        }

        return (reverse == number);
}

int main(int count, char *arguments[])
{
        unsigned maximum = 0;

        for (unsigned i = 999; i > 99; --i) {
                for (unsigned k = 999; k > 99; --k) {
                        unsigned const product = i * k;

                        if (product > maximum) {
                                if (isPalindrome(product) == true) {
                                        maximum = product;
                                }
                        }
                }
        }

        std::cout << maximum << '\n';
        return 0;
}