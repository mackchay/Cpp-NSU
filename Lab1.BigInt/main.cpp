#include <algorithm>
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
        this->number.erase(0, 1);
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
        return "-" + (number);
    }
    return number;
}

BigInt &BigInt::operator=(const BigInt &numberOther) {
    if (this == &numberOther) {
        return *this;
    }
    this->number = numberOther.number;
    this->IsNegative = numberOther.IsNegative;
    return *this;
}; //возможно присваивание самому себе!


BigInt BigInt::operator-() const {
    BigInt NumberOld(*this);
    NumberOld.IsNegative = !IsNegative;
    return NumberOld;
}

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

BigInt BigInt::operator++(int) {
    BigInt numberOld(*this);
    ++(*this);
    return numberOld;
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

const BigInt BigInt::operator--(int) {
    BigInt numberOld(*this);
    --(*this);
    return numberOld;
}

bool BigInt::operator==(const BigInt &other) const {
    return (this->number == other.number && this->IsNegative == other.IsNegative);
}

bool BigInt::operator!=(const BigInt &other) const {
    return !(*this == other);
}

bool BigInt::operator<(const BigInt &other) const {
    if (this->IsNegative == other.IsNegative) {
        if (other.size() != this->size()) {
            if (!this->IsNegative) {
                return this->size() < other.size();
            }
            return this->size() > other.size();
        }
        for (int i = 0; i < this->size(); i++) {
            if (this->number[i] != other.number[i]) {
                if (!this->IsNegative) {
                    return this->number[i] < other.number[i];
                }
                return this->number[i] > other.number[i];
            }

        }
        return false;
    }
    return this->IsNegative;
}

bool BigInt::operator<=(const BigInt &other) const {
    return *this == other || *this < other;
}

bool BigInt::operator>=(const BigInt &other) const {
    return *this == other || *this > other;
}


bool BigInt::operator>(const BigInt &other) const {
    return !(*this < other);
}


BigInt &BigInt::operator+=(const BigInt &other) {
    if (this->IsNegative != other.IsNegative) {
        this->IsNegative = !this->IsNegative;
        *this -= other;
        this->IsNegative = !this->IsNegative;
        return *this;
    }

    std::string thisNumber = this->number;
    std::string otherNumber = other.number;
    std::reverse(otherNumber.begin(), otherNumber.end());
    std::reverse(thisNumber.begin(), thisNumber.end());

    for (int i = 0; i < std::max(std::size(thisNumber), std::size(otherNumber)); i++) {
        if (i < std::size(otherNumber)) {
            thisNumber[i] += otherNumber[i] - '0';
        }
        if (thisNumber[i] > '9') {
            thisNumber[i] -= 10;
            if (!thisNumber[i + 1])
                thisNumber.append("0");
            thisNumber[i + 1] += 1;
        } else if (!thisNumber[i + 1] && i != (std::max(std::size(thisNumber), std::size(otherNumber)) - 1)) {
            thisNumber.append("0");
        }
    }

    std::reverse(thisNumber.begin(), thisNumber.end());
    this->number = thisNumber;

    return *this;

};

BigInt &BigInt::operator-=(const BigInt &other) {
    if (this->IsNegative != other.IsNegative) {
            this->IsNegative = !this->IsNegative;
            *this += other;
            this->IsNegative = !this->IsNegative;
            return *this;
    }


    std::string thisNumber;
    std::string otherNumber;
    if ((this->IsNegative && *this < other) || (!(this->IsNegative) && *this > other)) {
        thisNumber = this->number;
        otherNumber = other.number;

    } else {
        thisNumber = other.number;
        otherNumber = this->number;
        this->IsNegative = !this->IsNegative;
    }

    std::reverse(thisNumber.begin(), thisNumber.end());
    std::reverse(otherNumber.begin(), otherNumber.end());

    for (int i = 0; i < std::max(std::size(thisNumber), std::size(otherNumber)); i++) {
        thisNumber[i] += '0' - otherNumber[i];
        if (thisNumber[i] < '0' && i != std::max(std::size(thisNumber), std::size(otherNumber)) - 1) {
            thisNumber[i] += 10;
            thisNumber[i + 1] -= 1;
        }
        if (i == std::size(otherNumber) - 1 && i != std::max(std::size(thisNumber), std::size(otherNumber)) - 1) {
            otherNumber.append("0");
        }
    }


    std::reverse(thisNumber.begin(), thisNumber.end());


    int j = 0;

    while (thisNumber[j] == '0' && j != std::size(thisNumber) - 1) {
        thisNumber.erase(j, 1);
    }

    this->number = thisNumber;

    return *this;

};

BigInt &BigInt::operator*=(const BigInt &other) {
    for (BigInt i; i <= other; ++i) {
        *this += *this;
    }
    return *this;
};

size_t BigInt::size() const {
    return std::size(number);
}


BigInt operator+(const BigInt &first, const BigInt &second) {
    BigInt res;
    res += first;
    res += second;
    return res;

};

BigInt operator-(const BigInt &first, const BigInt &second) {
    BigInt res;
    res += first;
    res -= second;
    return res;
};

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
    BigInt b("-10000");
    BigInt c("-900");
    a = b - c;
    std::cout << &a << " " << &c << std::endl;
    std::cout << a.getBigInt() << std::endl;
    return 0;
}
