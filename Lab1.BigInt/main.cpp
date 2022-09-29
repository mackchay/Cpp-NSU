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
        if (number[i] < '0' || number[i] > '9') {
            throw std::invalid_argument("Invalid argument");
        }
    }
    this->number = number;
}
// бросать исключение std::invalid_argument при ошибке

BigInt::~BigInt() {

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
    return *this += 1;
};

BigInt BigInt::operator++(int) {
    BigInt numberOld(*this);
    ++(*this);
    return numberOld;
};

BigInt &BigInt::operator--() {
    return *this -= 1;
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

    std::string thisNumber;
    std::string otherNumber;
    std::string resNumber = "0";

    if (*this >= other > 0 && *this <= other <= 0) {
        thisNumber = this->number;
        otherNumber = other.number;
    } else {
        thisNumber = other.number;
        otherNumber = this->number;
    }
    std::reverse(otherNumber.begin(), otherNumber.end());
    std::reverse(thisNumber.begin(), thisNumber.end());

    for (size_t i = 0; i < std::size(thisNumber); i++) {
        if (!otherNumber[i])
            otherNumber.append("0");
        resNumber[i] += charToInt(thisNumber[i]) + charToInt(otherNumber[i]);
        resNumber.append("0");
        if (resNumber[i] > '9') {
            resNumber[i] -= 10;
            resNumber[i + 1] += 1;
        }

    }

    std::reverse(resNumber.begin(), resNumber.end());
    extraZeros(resNumber);
    this->number = resNumber;

    return *this;

}

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
    extraZeros(thisNumber);


    int j = 0;

    this->number = thisNumber;

    return *this;

}

BigInt &BigInt::operator*=(const BigInt &other) {
    if (this->number == "0" || other.number == "0") {
        *this = BigInt(0);
        return *this;
    }

    std::string thisNumber = this->number;
    std::string otherNumber = other.number;
    std::string curNumber = "0";
    int result;
    std::reverse(thisNumber.begin(), thisNumber.end());
    std::reverse(otherNumber.begin(), otherNumber.end());

    for (size_t i = 0; i < std::size(thisNumber); i++) {
        for (size_t j = 0; j < std::size(otherNumber); j++) {
            result = charToInt(thisNumber[i]) * charToInt(otherNumber[j]);

            if (std::size(curNumber) <= i + j + 1) {
                curNumber.append("0");
            }

            curNumber[i + j] += result % 10;
            curNumber[i + j + 1] += result / 10;

            if (curNumber[i + j] > '9') {
                curNumber[i + j] -= 10 * (charToInt(curNumber[i + j]) / 10);
                curNumber[i + j + 1] += 1;
            }
        }
    }
    std::reverse(curNumber.begin(), curNumber.end());
    extraZeros(curNumber);
    this->number = curNumber;
    this->IsNegative = this->IsNegative != other.IsNegative;
    return *this;
}

BigInt &BigInt::operator/=(const BigInt &other) {
    if (other == BigInt(0)) {
        throw std::invalid_argument("Zero exception");
    }

    this->IsNegative = this->IsNegative != other.IsNegative;


    BigInt cur;
    cur.number = "";
    std::string thisNumber = this->number;
    BigInt otherCopy = other;
    otherCopy.IsNegative = false;
    std::string resNumber;
    for (size_t i = 0; i < std::size(thisNumber); i++) {
        cur.number.push_back(thisNumber[i]);
        extraZeros(cur.number);
        if (cur < otherCopy) {
            resNumber.push_back('0');
        } else {
            int l = 0, r = 9, div = 0, x;
            while (l <= r) {
                x = (l + r) / 2;
                if (otherCopy * BigInt(x) <= cur) {
                    l += 1;
                    div = x;
                } else {
                    r -= 1;
                }
            }

            resNumber.push_back((char) (div + '0'));
            cur -= otherCopy * BigInt(div);
        }
    }
    extraZeros(resNumber);
    this->number = resNumber;

    return *this;
}

BigInt &BigInt::operator^=(const BigInt &other) {
    if (other == BigInt(0)){
        *this = BigInt(1);
    }
    for (BigInt i = 1; i < other; i++) {
        *this *= *this;
    }
    return *this;
}

BigInt &BigInt::operator%=(const BigInt &other) {
    if (other == BigInt(0)) {
        throw std::invalid_argument("Zero exception");
    }

    this->IsNegative = this->IsNegative != other.IsNegative;


    BigInt cur;
    cur.number = "";
    std::string thisNumber = this->number;
    BigInt otherCopy = other;
    otherCopy.IsNegative = false;
    for (size_t i = 0; i < std::size(thisNumber); i++) {
        cur.number.push_back(thisNumber[i]);
        extraZeros(cur.number);
        if (cur >= otherCopy) {
            int l = 0, r = 9, div = 0, x;
            while (l <= r) {
                x = (l + r) / 2;
                if (otherCopy * BigInt(x) <= cur) {
                    l += 1;
                    div = x;
                } else {
                    r -= 1;
                }
            }

            cur -= otherCopy * BigInt(div);
        }
    }
    extraZeros(cur.number);
    this->number = cur.number;
    return *this;
}

size_t BigInt::size() const {
    return std::size(number);
}

BigInt::operator std::string() const {
    return this->number;
};

BigInt::operator int() const{
    int res = 0;
    if (*this < BigInt(INT_MAX)) {
        for (int i = 0; i < (*this).size(); i++){
            res += this->number[(*this).size() - i] * 10^i;
        }
    }
    else {
        res = INT_MAX;
    }
    return res;
};

int charToInt(char x) {
    return x - '0';
}

int intToChar(int x) {
    return x + '0';
}

void extraZeros(std::string &str) {
    while (str[0] == '0' && std::size(str) > 1) {
        str.erase(0, 1);
    }
}

BigInt operator+(const BigInt &first, const BigInt &second) {
    BigInt res;
    res += first;
    res += second;
    return res;
}

BigInt operator-(const BigInt &first, const BigInt &second) {
    BigInt res;
    res += first;
    res -= second;
    return res;
}

BigInt operator*(const BigInt &first, const BigInt &second) {
    BigInt res(1);
    res *= first;
    res *= second;
    return res;
}

BigInt operator/(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res /= second;
    return res;
}

BigInt operator^(const BigInt &first, const BigInt &second) {
    BigInt res(1);
    for (BigInt i = 0; i < second; i++) {
        res *= first;
    }
    return res;
}

BigInt operator%(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res /= second;
    return res;
};

BigInt operator&(const BigInt &, const BigInt &);

BigInt operator|(const BigInt &, const BigInt &);

std::ostream &operator<<(std::ostream &o, const BigInt &i);


int main() {
    BigInt a;
    std::string first;
    std::string second;
    std::cin >> first;
    std::cin >> second;
    BigInt b(first);
    BigInt c(second);
    a = b;
    a %= c;
    std::cout << a.getBigInt() << std::endl;
    return 0;
}
