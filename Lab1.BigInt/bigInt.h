#ifndef LAB1_BIGINT_BIGINT_H
#define LAB1_BIGINT_BIGINT_H
#include <iostream>
#include <string>


class BigInt {
private:
    std::string number;
    bool IsNegative;

public:
    BigInt();

    BigInt(int);

    BigInt(std::string);

    BigInt(const BigInt &);

    ~BigInt();

    std::string getBigInt() const;

    BigInt &operator=(const BigInt &);

    BigInt operator~() const;

    BigInt &operator++();

    BigInt operator++(int);

    BigInt &operator--();

    const BigInt operator--(int);

    BigInt &operator+=(const BigInt &);

    BigInt &operator*=(const BigInt &);

    BigInt &operator-=(const BigInt &);

    BigInt &operator/=(const BigInt &);

    BigInt &operator^=(const BigInt &);

    BigInt &operator%=(const BigInt &);

    BigInt &operator&=(const BigInt &);

    BigInt &operator|=(const BigInt &);

    BigInt operator+() const;  // unary +
    BigInt operator-() const;  // unary -

    bool operator==(const BigInt &) const;

    bool operator!=(const BigInt &) const;

    bool operator<(const BigInt &) const;

    bool operator>(const BigInt &) const;

    bool operator<=(const BigInt &) const;

    bool operator>=(const BigInt &) const;

    operator int() const;

    operator std::string() const;

    size_t size() const;  // size in bytes
};

int charToInt(char);

void extraZeros(std::string &);

int intToChar(int x);

BigInt operator+(const BigInt &, const BigInt &);

BigInt operator-(const BigInt &, const BigInt &);

BigInt operator*(const BigInt &, const BigInt &);

BigInt operator/(const BigInt &, const BigInt &);

BigInt operator^(const BigInt &, const BigInt &);

BigInt operator%(const BigInt &, const BigInt &);

BigInt operator&(const BigInt &, const BigInt &);

BigInt operator|(const BigInt &, const BigInt &);

std::ostream &operator<<(std::ostream &o, const BigInt &i);

#endif //LAB1_BIGINT_BIGINT_H
