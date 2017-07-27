#include <iostream>

int main(int count, char *arguments[])
{
    /* sum(1 ... n) = 0.5 * n * (n + 1)
     * sum(1 ... n, k) = k * 0.5 * r * (r + 1) | { r = n / k }
     *
     * a = sum(1 ... 999, 3) = 3 * 0.5 * 333 * (333 + 1) = 166833
     * b = sum(1 ... 995, 5) = 5 * 0.5 * 199 * (199 + 1) = 99500
     *
     * lcm(3, 5) = 15
     *
     * c = sum(1 ... 66, 15) = 15 * 0.5 * 66 * (66 + 1) = 33165
     *
     * result = a + b - c = 166833 + 99500 - 33165 = 233168 */

    std::cout << 233168 << '\n';
    return 0;
}