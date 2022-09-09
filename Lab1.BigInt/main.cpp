#include <iostream>
#include <string>


class BigInt {
private:
    std::string Number;
    bool IsNegative;

public:
    BigInt() {
        Number = "0";
        IsNegative = false;
    };

    BigInt(int Number) {
        this->Number = std::to_string(Number);
        if (Number >= 0) {
            IsNegative = false;
        } else {
            IsNegative = true;
        }
    };

    BigInt(std::string Number) {
        if (Number[0] == '-') {
            Number.erase(0,1);
            this->IsNegative = true;
        }
        else{
            this->IsNegative = false;
        }

        for (int i = 0; i < std::size(Number); i++) {
            if (Number[i] < '0' || Number[i] > '9' || Number[0] == '0' ) {
                throw std::invalid_argument("Invalid argument");
            }
        }
        this->Number = Number;
    };
    // бросать исключение std::invalid_argument при ошибке

    BigInt(const BigInt &);

    ~BigInt() {
        std::cout << "Destructing " << this << std::endl;
    };

    BigInt &operator=(const BigInt &NewNumber) {
        this->Number = NewNumber.Number;
        this->IsNegative = NewNumber.IsNegative;
        return *this;
    };  //возможно присваивание самому себе!

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
    BigInt c("21234866");
    a = c;

    return 0;
}
