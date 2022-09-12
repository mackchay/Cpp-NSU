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

    BigInt &operator=(const BigInt &number);

    BigInt operator~() const;

    BigInt &operator++();

    const BigInt operator++(int) const;

    BigInt &operator--();

    const BigInt operator--(int) const;

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

BigInt::BigInt() {
    number = "0";
    IsNegative = false;
}

BigInt::BigInt(int number) {
    this->number = std::to_string(number);
    if (number >= 0) {
        IsNegative = false;
    } else {
        IsNegative = true;
    }
}

BigInt::BigInt(std::string number) {
    if (number[0] == '-') {
        number.erase(0, 1);
        this->IsNegative = true;
    } else {
        this->IsNegative = false;
    }

    for (int i = 0; i < std::size(number); i++) {
        if (number[i] < '0' || number[i] > '9' || number[0] == '0') {
            throw std::invalid_argument("Invalid argument");
        }
    }
    this->number = number;
}
// бросать исключение std::invalid_argument при ошибке

BigInt::~BigInt() {
    std::cout << "Destructing " << this << std::endl;
}

BigInt::BigInt(const BigInt &number) {
    this->number = number.number;
    IsNegative = number.IsNegative;
}

std::string BigInt::getBigInt() const {
    return number;
}

BigInt &BigInt::operator=(const BigInt &number) {
    this->number = number.number;
    this->IsNegative = number.IsNegative;
    return *this;
}; //возможно присваивание самому себе!

BigInt &BigInt::operator++() {
    uint32_t i = std::size(number) - 1;
    number[i]++;
    while (number[i] > '9' && i >= 0) {
        number[i] -= 10;
        i--;
        number[i]++;
    }
    if (number[0] > '9') {
        number[0] -= 10;
        number = "1" + number;
    }
    return *this;
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


int main() {
    BigInt a;
    BigInt b(10);
    BigInt c("-21234866");
    a = c;
    ++b;
    std::cout << &a << " " << &c << std::endl;
    std::cout << b.getBigInt() << std::endl;
    return 0;
}
