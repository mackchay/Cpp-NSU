#include "bigInt.h"

BigInt::BigInt() {
    number = "0";
    IsNegative = false;
}

BigInt::BigInt(int number) {
    this->number = std::to_string(number);
    if (number >= 0) {
        IsNegative = false;
    } else {
        this->number.erase(0,1);
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
    if (IsNegative) {
        return ("-" + number);
    }
    return number;
}

BigInt &BigInt::operator=(const BigInt &number) {
    this->number = number.number;
    this->IsNegative = number.IsNegative;
    return *this;
}; //возможно присваивание самому себе!

BigInt &BigInt::operator++() {
    uint32_t i = std::size(number) - 1;
    number[i] += 1 - IsNegative * 2;
    while ((number[i] > '9' || number[i] < '0') && i >= 1) {
        number[i] -= 10 - IsNegative * 20;
        i--;
        number[i] += 1 - IsNegative * 2;
    }
    if (number[0] > '9') {
        number[0] -= 10;
        number = "1" + number;
    }
    if (number[0] == '0') {
        number.erase(0, 1);
    }
    return *this;
};

BigInt &BigInt::operator--() {
    uint32_t i = std::size(number) - 1;
    number[i] -= 1 - IsNegative * 2;
    while ((number[i] > '9' || number[i] < '0') && i > 0) {
        number[i] += 10 - IsNegative * 20;
        i--;
        number[i] -= 1 - IsNegative * 2;
    }
    if (number[0] > '9') {
        number[0] -= 10;
        number = "1" + number;
    }
    if (number[0] == '0') {
        number.erase(0, 1);
    }
    return *this;
};

/*BigInt &BigInt::operator+=(const BigInt &number) {
    uint32_t i = std::size(number) - 1;
    this->number += number.number[i];


};*/


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
    BigInt b(-10);
    BigInt c("-1099");
    a = c;
    --a;
    std::cout << &a << " " << &c << std::endl;
    std::cout << a.getBigInt() << std::endl;
    return 0;
}
