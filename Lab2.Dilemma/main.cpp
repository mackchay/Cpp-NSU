#include <memory>

int main() {
    StrategyFactory<std::string, Strategy> strategyFactory;

    strategyFactory.add<AlwaysBetray>("AlwaysBetray");
    strategyFactory.add<AlwaysBetray>("AlwaysCooperate");

    Strategy *Ivan = strategyFactory.get("AlwaysCooperate")();
    Strategy *Igor = strategyFactory.get("AlwaysBetray")();
    Igor -> info();
    Matrix object;
    object.readMatrix();
    object.printMatrix();

    return 0;
}
