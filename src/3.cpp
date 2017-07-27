#include <iostream>

#include <cmath>
#include <cstdint>

static uint64_t exponentiate(
    uint64_t base, uint64_t exponent, uint64_t modulus) noexcept
{
    uint64_t result = 1;

    if (modulus == 1) {
        return 0;
    }

    base %= modulus;

    for (; exponent > 0; exponent >>= 1) {
        if ((exponent & 1) == 1) {
            result = base * result % modulus;
        }

        base = (base * base) % modulus;
    }

    return result;
}

static bool isWitness(uint64_t number, uint64_t exponent, uint64_t coefficient,
    uint64_t candidate) noexcept
{
    uint64_t i = exponentiate(candidate, coefficient, number);

    if (i == 1) {
        return false;
    }

    for (; exponent != 0; --exponent) {
        if (i == number - 1) {
            return false;
        }

        i = (i * i) % number;

        if (i == 1) {
            return true;
        }
    }

    return (i != 1);
}

static bool isWitness(uint64_t number, uint64_t exponent, uint64_t coefficient,
    std::initializer_list<uint64_t> candidates) noexcept
{
    bool result = false;

    for (uint64_t i : candidates) {
        result |= isWitness(number, exponent, coefficient, i);
    }

    return result;
}

static bool isPrime(uint64_t number) noexcept
{
    if (number == 2 || number == 3) {
        return true;
    } else if (number < 5 || (number & 1) == 0 || (number % 3) == 0) {
        return false;
    }

    uint64_t coefficient = number >> 1;
    uint64_t exponent = 1;

    for (; (coefficient & 1) == 0; coefficient >>= 1) {
        ++exponent;
    }

    if (number < 2047) {
        return (isWitness(number, exponent, coefficient, 2) == false);
    } else if (number < 1373653) {
        return (isWitness(number, exponent, coefficient, {2, 3}) == false);
    } else if (number < 9080191) {
        return (isWitness(number, exponent, coefficient, {31, 73}) == false);
    } else if (number < 25326001) {
        return (isWitness(number, exponent, coefficient, {2, 3, 5}) == false);
    } else if (number < 3215031751) {
        return (
            isWitness(number, exponent, coefficient, {2, 3, 5, 7}) == false);
    } else if (number < 4759123141) {
        return (isWitness(number, exponent, coefficient, {2, 7, 61}) == false);
    } else if (number < 1122004669633) {
        return (isWitness(number, exponent, coefficient,
                    {2, 13, 23, 1662803}) == false);
    } else if (number < 2152302898747) {
        return (isWitness(number, exponent, coefficient, {2, 3, 5, 7, 11}) ==
            false);
    } else if (number < 3474749660383) {
        return (isWitness(number, exponent, coefficient,
                    {2, 3, 5, 7, 11, 13}) == false);
    } else if (number < 341550071728321) {
        return (isWitness(number, exponent, coefficient,
                    {2, 3, 5, 7, 11, 13, 17}) == false);
    } else if (number < 3825123056546413051) {
        return (isWitness(number, exponent, coefficient,
                    {2, 3, 5, 7, 11, 13, 17, 19, 23}) == false);
    }

    return (isWitness(number, exponent, coefficient,
                {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) == false);
}

int main(int count, char *arguments[])
{
    uint64_t i = static_cast<uint64_t>(std::sqrt(600851475143));

    for (; i > 1; --i) {
        if (600851475143 % i == 0 && isPrime(i) == true) {
            std::cout << i << '\n';
            return 0;
        }
    }

    return 1;
}