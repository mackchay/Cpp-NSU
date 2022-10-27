#ifndef LAB1_BIGINT_BIGINT_H
#define LAB1_BIGINT_BIGINT_H

#include <iostream>
#include <string>


class BigInt {

public:
    BigInt();

    BigInt(int);

    BigInt(std::string);

    BigInt(const BigInt &);

    ~BigInt();

    BigInt &operator=(const BigInt &);

    BigInt operator~() const;

    BigInt &operator++();

    const BigInt operator++(int);

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

    explicit operator int() const;

    explicit operator std::string() const;

    size_t size() const;  // size in bytes


private:

    std::string number;
    bool IsNegative;
};


BigInt operator+(const BigInt &, const BigInt &);

BigInt operator-(const BigInt &, const BigInt &);

BigInt operator*(const BigInt &, const BigInt &);

BigInt operator/(const BigInt &, const BigInt &);

BigInt operator^(const BigInt &, const BigInt &);

BigInt operator%(const BigInt &, const BigInt &);

BigInt operator&(const BigInt &, const BigInt &);

BigInt operator|(const BigInt &, const BigInt &);

std::ostream &operator<<(std::ostream &o, const BigInt &i);

BigInt pow(const BigInt &, const BigInt &);

int charToInt(char);

void extraZeros(std::string &);

std::string fromDecadeToBin(std::string );

std::string fromBinToDecade(std::string );

int intToChar(BigInt x);

#endif //LAB1_BIGINT_BIGINT_H
