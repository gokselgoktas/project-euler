#include <iostream>
#include <stack>

static unsigned getGreatestCommonDivisor(unsigned i, unsigned k) noexcept
{
        unsigned divisor = 0;

        while (k != 0) {
                divisor = k;

                k = i % k;
                i = divisor;
        }

        return divisor;
}

static unsigned getLowestCommonMultiple(unsigned i, unsigned k) noexcept
{
        return ((i * k) / getGreatestCommonDivisor(i, k));
}

int main(int count, char *arguments[])
{
        std::stack<unsigned> stack;

        for (unsigned i = 1; i < 20; ++i) {
                stack.push(i);
        }

        while (stack.size() != 1) {
                unsigned k = stack.top();
                stack.pop();

                unsigned i = stack.top();
                stack.pop();

                stack.push(getLowestCommonMultiple(i, k));
        }

        std::cout << stack.top() << '\n';
        return 0;
}
