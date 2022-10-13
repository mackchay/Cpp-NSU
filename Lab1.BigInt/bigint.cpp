#include "bigInt.h"
#include <algorithm>

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

    for (size_t i = 0; i < number.size(); i++) {
        if (number[i] < '0' || number[i] > '9') {
            throw std::invalid_argument("Invalid argument");
        }
    }
    this->number = number;
}
// бросать исключение std::invalid_argument при ошибке

BigInt::~BigInt() = default;

BigInt::BigInt(const BigInt &number) {
    this->number = number.number;
    IsNegative = number.IsNegative;
}

BigInt &BigInt::operator=(const BigInt &numberOther) {
    if (this == &numberOther) {
        return *this;
    }
    this->number = numberOther.number;
    this->IsNegative = numberOther.IsNegative;
    return *this;
} //возможно присваивание самому себе!


BigInt BigInt::operator~() const {
    BigInt numberOld = *this;
    numberOld++;
    numberOld.IsNegative = !numberOld.IsNegative;
    return numberOld;
}


BigInt BigInt::operator+() const {
    BigInt numberOld(*this);
    return numberOld;
}

BigInt BigInt::operator-() const {
    BigInt numberOld(*this);
    numberOld.IsNegative = !IsNegative;
    return numberOld;
}

BigInt &BigInt::operator++() {
    return *this += 1;
}

const BigInt BigInt::operator++(int) {
    BigInt numberOld(*this);
    ++(*this);
    return numberOld;
}

BigInt &BigInt::operator--() {
    return *this -= 1;
}

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
        if (other.number.size() != this->number.size()) {
            if (!this->IsNegative) {
                return this->number.size() < other.number.size();
            }
            return this->number.size() > other.number.size();
        }
        for (size_t i = 0; i < this->number.size(); i++) {
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
    return !(*this < other) && !(*this == other);
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

    if ((*this >= other && other >= 0) || (*this <= other && other < 0)) {
        thisNumber = this->number;
        otherNumber = other.number;
    } else {
        thisNumber = other.number;
        otherNumber = this->number;
    }
    std::reverse(otherNumber.begin(), otherNumber.end());
    std::reverse(thisNumber.begin(), thisNumber.end());

    for (size_t i = 0; i < thisNumber.size(); i++) {
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
    if ((this->IsNegative && *this <= other) || (!(this->IsNegative) && *this >= other)) {
        thisNumber = this->number;
        otherNumber = other.number;

    } else {
        thisNumber = other.number;
        otherNumber = this->number;
        this->IsNegative = !this->IsNegative;
    }

    std::reverse(thisNumber.begin(), thisNumber.end());
    std::reverse(otherNumber.begin(), otherNumber.end());

    for (size_t i = 0; i < std::max(thisNumber.size(), otherNumber.size()); i++) {
        thisNumber[i] += '0' - otherNumber[i];
        if (thisNumber[i] < '0' && i != std::max(thisNumber.size(), otherNumber.size()) - 1) {
            thisNumber[i] += 10;
            thisNumber[i + 1] -= 1;
        }
        if (i == otherNumber.size() - 1 && i != std::max(thisNumber.size(), otherNumber.size()) - 1) {
            otherNumber.append("0");
        }
    }


    std::reverse(thisNumber.begin(), thisNumber.end());
    extraZeros(thisNumber);

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

    for (size_t i = 0; i < thisNumber.size(); i++) {
        for (size_t j = 0; j < otherNumber.size(); j++) {
            result = charToInt(thisNumber[i]) * charToInt(otherNumber[j]);

            if (curNumber.size() <= i + j + 1) {
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
    for (size_t i = 0; i < thisNumber.size(); i++) {
        cur.number.push_back(thisNumber[i]);
        extraZeros(cur.number);
        if (cur < otherCopy) {
            resNumber.push_back('0');
        } else {
            int l = 0, r = 10, div = 0, x;
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
    std::string binaryThis = std::string(*this);
    std::string binaryOther = std::string(other);

    binaryThis = fromDecadeToBin(binaryThis);
    binaryOther = fromDecadeToBin(binaryOther);
    std::reverse(binaryThis.begin(), binaryThis.end());
    std::reverse(binaryOther.begin(), binaryOther.end());

    for (size_t i = 0; i < std::max(binaryThis.size(), binaryOther.size()); i++) {
        if (i == binaryThis.size()) {
            if (*this >= 0) {
                binaryThis.append("0");
            } else {
                binaryThis.append("1");
            }
        }
        if (i == binaryOther.size()) {
            if (other >= 0) {
                binaryOther.append("0");
            } else {
                binaryOther.append("1");
            }
        }
        if (binaryThis[i] == binaryOther[i]) {
            binaryThis[i] = '0';
        } else {
            binaryThis[i] = '1';
        }
    }

    std::reverse(binaryThis.begin(), binaryThis.end());
    if (this->IsNegative ^ other.IsNegative) {
        binaryThis.insert(binaryThis.begin(), '-');
    }
    binaryThis = fromBinToDecade(binaryThis);
    *this = BigInt(binaryThis);

    return *this;
}

BigInt &BigInt::operator%=(const BigInt &other) {
    if (other == BigInt(0)) {
        throw std::invalid_argument("Zero exception");
    }

    this->IsNegative = (this->IsNegative != other.IsNegative);

    BigInt cur;
    cur.number = "";
    std::string thisNumber = this->number;
    BigInt otherCopy = other;
    otherCopy.IsNegative = false;
    for (size_t i = 0; i < thisNumber.size(); i++) {
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

BigInt &BigInt::operator&=(const BigInt &other) {
    std::string binaryThis = std::string(*this);
    std::string binaryOther = std::string(other);

    binaryThis = fromDecadeToBin(binaryThis);
    binaryOther = fromDecadeToBin(binaryOther);
    std::reverse(binaryThis.begin(), binaryThis.end());
    std::reverse(binaryOther.begin(), binaryOther.end());

    for (size_t i = 0; i < std::max(binaryThis.size(), binaryOther.size()); i++) {
        if (i == binaryThis.size()) {
            if (*this >= 0) {
                binaryThis.append("0");
            } else {
                binaryThis.append("1");
            }
        }
        if (i == binaryOther.size()) {
            if (other >= 0) {
                binaryOther.append("0");
            } else {
                binaryOther.append("1");
            }
        }
        if (binaryThis[i] != binaryOther[i]) {
            binaryThis[i] = '0';
        }
    }

    std::reverse(binaryThis.begin(), binaryThis.end());
    if (this->IsNegative && other.IsNegative) {
        binaryThis.insert(binaryThis.begin(), '-');
    }
    binaryThis = fromBinToDecade(binaryThis);
    *this = BigInt(binaryThis);

    return *this;
}

BigInt &BigInt::operator|=(const BigInt &other) {
    std::string binaryThis = std::string(*this);
    std::string binaryOther = std::string(other);
    binaryThis = fromDecadeToBin(binaryThis);
    binaryOther = fromDecadeToBin(binaryOther);
    std::reverse(binaryThis.begin(), binaryThis.end());
    std::reverse(binaryOther.begin(), binaryOther.end());
    for (size_t i = 0; i < std::max(binaryThis.size(), binaryOther.size()); i++) {
        if (i == binaryThis.size()) {
            if (*this >= 0) {
                binaryThis.append("0");
            } else {
                binaryThis.append("1");
            }
        }

        if (i == binaryOther.size()) {
            if (other >= 0) {
                binaryOther.append("0");
            } else {
                binaryOther.append("1");
            }
        }

        if (binaryThis[i] != binaryOther[i]) {
            binaryThis[i] = '1';
        }
    }

    std::reverse(binaryThis.begin(), binaryThis.end());
    if (this->IsNegative || other.IsNegative) {
        binaryThis.insert(binaryThis.begin(), '-');
    }
    binaryThis = fromBinToDecade(binaryThis);
    *this = BigInt(binaryThis);

    return *this;
}


size_t BigInt::size() const {
    return number.size();
}

BigInt::operator std::string() const {
    if (*this >= 0) {
        return this->number;
    } else {
        return "-" + this->number;
    }
}

BigInt::operator int() const {
    int res = 0;
    for (size_t i = 0; i < this->number.size(); i++) {
        res += this->number[this->number.size() - i] * int(pow(10, i));
    }
    return res;
}

int charToInt(char x) {
    return x - '0';
}

int intToChar(BigInt &x) {
    return int(x) + '0';
}

void extraZeros(std::string &str) {
    while (str[0] == '0' && str.size() > 1) {
        str.erase(0, 1);
    }
}

BigInt operator+(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res += second;
    return res;
}

BigInt operator-(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res -= second;
    return res;
}

BigInt operator*(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res *= second;
    return res;
}

BigInt operator/(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res /= second;
    return res;
}

BigInt operator^(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res ^= second;
    return res;
}

BigInt operator%(const BigInt &first, const BigInt &second) {
    BigInt res = first;
    res %= second;
    return res;
}

BigInt operator&(const BigInt &first, const BigInt &second) {
    BigInt resNumber = first;
    resNumber &= second;
    return resNumber;
}

BigInt operator|(const BigInt &first, const BigInt &second) {
    BigInt resNumber = first;
    resNumber |= second;
    return resNumber;
}

std::ostream &operator<<(std::ostream &o, const BigInt &i) {
    return o << std::string(i);
}

BigInt pow(const BigInt &first, const BigInt &second) {
    BigInt res = 1;
    for (BigInt i = 0; i < second; i++) {
        res *= first;
    }
    return res;
}

std::string fromDecadeToBin(std::string number) {
    BigInt cur(number);
    std::string binary;

    while (cur > BigInt(0)) {
        binary.append(std::string(cur % BigInt(2)));
        cur /= 2;
    }

    while (cur < -BigInt(0)) {
        binary.append(std::string(cur % BigInt(2)).erase(0, 1));
        cur /= 2;
    }

    std::reverse(binary.begin(), binary.end());
    if (number[0] == '-') {
        for (size_t i = 0; i < binary.size(); i++) {
            if (binary[i] == '0') {
                binary[i] = '1';
            } else {
                binary[i] = '0';
            }
        }
        binary.insert(binary.begin(), '1');
        binary = fromDecadeToBin(std::string(BigInt(fromBinToDecade(binary)) + 1));
        binary.erase(binary.begin());
    }
    return binary;
}

std::string fromBinToDecade(std::string number) {
    BigInt decade;
    if (number[0] == '-') {
        number[0] = '1';
        BigInt cur(number);
        number = std::string(BigInt(fromBinToDecade(number)) - 1);
        number = fromDecadeToBin(number);
        number.erase(number.begin());
        for (size_t i = 0; i < number.size(); i++) {
            if (number[i] == '1') {
                number[i] = '0';
            } else {
                number[i] = '1';
            }
        }
        decade = -BigInt(fromBinToDecade(number));
    } else {
        for (size_t i = 0; i < number.size(); i++) {
            decade += charToInt(number[i]) *
                      pow(BigInt(2), BigInt(number.size() - 1 - i));
        }
    }
    number = std::string(decade);
    return number;
}


