#include <iostream>

int main(int count, char *arguments[])
{
        unsigned i = 1;
        unsigned k = 2;

        unsigned sum = 2;

        for (; sum < 4000001; sum += k) {
                unsigned r = i;

                i += k << 1;
                k += (r << 1) + (k << 1);
        }

        std::cout << sum << '\n';
        return 0;
}