#include <iostream>
#include <string>

static void add(std::string &result, std::string const &number)
{
    unsigned accumulator = 0;

    auto i = result.rbegin();
    for (auto k = number.rbegin(); k != number.rend(); ++k) {
        accumulator += static_cast<unsigned>((*i - '0') + (*k - '0'));

        *i = static_cast<char>(accumulator % 10) + '0';

        accumulator /= 10;
        ++i;
    }

    while (accumulator > 0) {
        if (i != result.rend()) {
            accumulator += static_cast<unsigned>(*i - '0');
            *i = static_cast<char>(accumulator % 10) + '0';

            ++i;
        } else {
            result.insert(0, 1, static_cast<char>(accumulator) + '0');
        }

        accumulator /= 10;
    }
}

int main(int count, char *arguments[])
{
    std::string result = "2";

    for (int i = 0; i < 999; ++i) {
        add(result, result);
    }

    unsigned sum = 0;
    for (auto i : result) {
        sum += static_cast<unsigned>(i - '0');
    }

    std::cout << sum << '\n';
    return 0;
}