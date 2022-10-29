#include "strategy_make.h"
#include <memory>


int main() {
    auto strategyFactory = std::make_unique<StrategyFactory>();
    std::string Ivan = "AlwaysCooperate";
    strategyFactory->create(Ivan);
    return 0;
}
