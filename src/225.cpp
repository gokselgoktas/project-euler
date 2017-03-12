#include <iostream>

int main(int count, char *arguments[])
{
        unsigned divisor = 27;
        unsigned counter = 1;

        while (counter < 124) {
                divisor += 2;

                unsigned terms[3] = { 1, 1, 3 };
                while (terms[0] * terms[1] * terms[2] > 1) {
                        unsigned k = terms[2];

                        terms[2] += terms[0] + terms[1];
                        terms[0] = terms[1];
                        terms[1] = k;

                        terms[2] %= divisor;

                        if (terms[2] == 0) {
                                break;
                        }
                }

                counter += static_cast<unsigned>(terms[2] != 0);
        }

        std::cout << divisor << '\n';
        return 0;
}
