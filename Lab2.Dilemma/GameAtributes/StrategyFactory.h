#ifndef LAB2_DILEMMA_STRATEGYFACTORY_H
#define LAB2_DILEMMA_STRATEGYFACTORY_H

#include <map>

template<class ID, class Base, class ...Args>
class StrategyFactory {
private:
    typedef Base *(*creator)(Args...);

    std::map<ID, creator> strategyMap;
    template<class Derived>
    static Base *create(Args...args) {
        return new Derived(args...);
    };

public:
    StrategyFactory() = default;

    template<class Derived>
    void add(ID id) {
        strategyMap[id] = &create<Derived>;
    }

    creator get(ID id) {
        return strategyMap[id];
    }

    bool isStrategy(ID id) {
        if (strategyMap.contains(id))
            return true;
        return false;
    }
};


#endif //LAB2_DILEMMA_STRATEGYFACTORY_H
