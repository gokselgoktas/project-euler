#include <iostream>

int main(int count, char *arguments[])
{
        /* The number of paths through a lattice from the origin to { a, b } is
         * given by Hilton-Pedersen:
         * (a + b) | a = (a + b)! / ((a + b) - a)! * a! = (a + b)! / b! * a!
         *
         * The number of paths in a 2 * 2 grid:
         * (2 + 2) | 2 = 4! / (2! * 2!) = 6
         *
         * The number of paths in a 20 * 20 grid:
         * (20 + 20)! / (20! * 20!) = 40! / (20! * 20!) = 137846528820 */

        std::cout << 137846528820 << '\n';
        return 0;
}