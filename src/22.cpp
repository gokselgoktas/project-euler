#include <iostream>

#include <cstdint>
#include <fstream>
#include <set>

static uint64_t getScore(std::string const &string) noexcept
{
    uint64_t score = 0;

    for (auto i : string) {
        score += static_cast<uint64_t>(i - '@');
    }

    return score;
}

int main(int count, char *arguments[])
{
    if (count == 1) {
        return 1;
    }

    std::ifstream input(arguments[1]);

    if (input.fail() == true) {
        return 1;
    }

    std::set<std::string> container;
    std::istream_iterator<std::string> iterator(input);

    std::copy(iterator, std::istream_iterator<std::string>(),
        std::inserter(container, container.begin()));

    uint64_t score = 0;
    uint64_t position = 1;

    for (auto i : container) {
        score += getScore(i) * position;
        ++position;
    }

    std::cout << score << '\n';
    return 0;
}