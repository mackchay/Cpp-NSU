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

    BigInt(int number);

    BigInt(std::string number);

    BigInt(const BigInt &number);

    ~BigInt();

    std::string getBigInt() const;

    BigInt &operator=(const BigInt &numberOther);

     BigInt operator~() const;

    BigInt &operator++();

    const BigInt operator++(int);

    BigInt &operator--();

    const BigInt operator--(int);

    BigInt &operator+=(const BigInt &number);

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

#endif //LAB1_BIGINT_BIGINT_H
