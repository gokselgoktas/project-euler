#include <iostream>

int main(int count, char *arguments[])
{
    for (unsigned i = 1; i < 500; ++i) {
        for (unsigned k = ((1000 - i) >> 1); k > 0; --k) {
            unsigned r = 1000 - (i + k);

            unsigned product = i * i + k * k - r * r;

            if (product == 0) {
                std::cout << i * k * r << '\n';
                return 0;
            }
        }
    }
}