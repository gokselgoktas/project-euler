#include <iostream>

int main(int count, char *arguments[])
{
    /* sum(1 ... n) = 0.5 * n * (n + 1)
     * sos(1 ... n) = 0.16666... * n * (n + 1) * (2 * n + 1)
     *
     * a = sum(1 ... 100) = 0.5 * 100 * (100 + 1) = 5050
     * b = sos(1 ... 100) = 0.16666... * 100 * (100 + 1) * (2 * 100 + 1)
     * b = 338350
     *
     * result = abs(b - a * a) = 25164150 */

    std::cout << 25164150 << '\n';
    return 0;
}