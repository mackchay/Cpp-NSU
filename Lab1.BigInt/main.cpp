#include <iostream>

class BigInt {
private:
    std::string Number;

public:

    BigInt() {
        Number = "";
    }

    BigInt(int IntNumber) {
        Number = std::to_string(IntNumber);
    }

    BigInt(std::string StrNumber) {
        Number += StrNumber;
    }
};

int main() {
    BigInt();
    BigInt(10);
    BigInt("21234566");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
