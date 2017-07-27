#include <array>
#include <iostream>

static constexpr unsigned getLetterCount(unsigned number) noexcept
{
    unsigned count = 0;

    constexpr std::array<unsigned, 29> counts = {{0, 3, 3, 5, 4, 4, 3, 5, 5, 4,
        3, 6, 6, 8, 8, 7, 7, 9, 8, 8, 6, 6, 5, 5, 5, 7, 6, 6}};

    if (number < 21) {
        count = counts[number];
    } else if (number < 100) {
        count = counts[20 + (number / 10) - 2];

        if (number % 10 > 0) {
            count += counts[number % 10];
        }
    } else {
        count = counts[number / 100] + 7;

        if (number % 100 > 0) {
            count += getLetterCount(number % 100) + 3;
        }
    }

    return count;
}

int main(int count, char *arguments[])
{
    unsigned result = 0;

    for (unsigned i = 1; i < 1000; ++i) {
        result += getLetterCount(i);
    }

    result += 11;

    std::cout << result << '\n';
    return 0;
}