#include "bigInt.h"

int main() {
    BigInt a;
    std::string first;
    std::string second;
    std::cin >> first;
    std::cin >> second;
    BigInt b(first);
    BigInt c(second);
    a = b;
    a ^= c;
    std::cout<<a<<std::endl;
    //std::cout << fromDecadeToBin(std::string(a)) << std::endl;
    //std::cout << fromBinToDecade(std::string (fromDecadeToBin(std::string(a)))) << std::endl;
    return 0;
}
