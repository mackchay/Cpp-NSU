#ifndef LAB2_DILEMMA_STRATEGY_MAKE_H
#define LAB2_DILEMMA_STRATEGY_MAKE_H
#include <iostream>
#include <map>
#include "strategy_type.h"

class abstractStrategyCreator {
public:
    virtual Strategy * create() const = 0;
};


template <class T>
class StrategyCreator : public abstractStrategyCreator {
public:
    virtual Strategy *create() const {
        return new T();
    }
};


class StrategyFactory {

protected:
    typedef std::map<std::string, abstractStrategyCreator *> FactoryMap;
    FactoryMap factory;

public:

    StrategyFactory() {

    }

    virtual ~StrategyFactory() = default;

    template <class T>
    void add(const std::string &id) {
        auto it = factory.find(id);
        if (it == factory.end()) {
            factory[id] = new StrategyCreator<T>();
        }
    }

    Strategy *create(const std::string &id)
    {
        auto it = factory.find(id);
        if (it != factory.end())
            return it->second->create();
        return nullptr;
    }
};


#endif
