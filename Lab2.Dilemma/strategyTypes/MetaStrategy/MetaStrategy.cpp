#include <fstream>
#include "MetaStrategy.h"
#include "../AlwaysDefect/AlwaysDefect.h"
#include "../AlwaysCooperate/AlwaysCooperate.h"
#include "../RandomAct/RandomAct.h"
#include "../CoopUntilDefect/CoopUntilDefect.h"
#include "../CustomAct/CustomAct.h"
#include "../RatCat/RatAct.h"


void MetaStrategy::registerFactory() {
    strategyFactory.add<AlwaysDefect>("AlwaysDefect");
    strategyFactory.add<AlwaysCooperate>("AlwaysCooperate");
    strategyFactory.add<RandomAct>("RandomAct");
    strategyFactory.add<CoopUntilDefect>("CoopUntilDefect");
    strategyFactory.add<CustomAct>("CustomAct");
    strategyFactory.add<RatAct>("RatAct");
}

MetaStrategy::MetaStrategy() {
    registerFactory();

    countCoop = 0, countDefect = 0;
    fileName = "/metaStrategy.txt";
}

void MetaStrategy::reset() {
    for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
        (*it)->reset();
    }
    points = 0,
    countCoop = 0, countDefect = 0;
}

std::string MetaStrategy::info() {
    return "MetaStrategy";
}

void MetaStrategy::setOpponentActs(const std::string &acts) {
    log.add(acts);
}

void MetaStrategy::setDirName(const std::string &dirName) {
    std::ifstream fin;
    std::string strategyName;

    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    fin.open(dirName + fileName);
    for (size_t i = 0; i < 3; i++) {
        fin >> strategyName;
        if (strategyFactory.contains(strategyName)) {
            strategyList.push_back(strategyFactory.get(strategyName)());
        } else {
            throw std::invalid_argument("Incorrect data in " + fileName);
        }
    }
    fin.close();
}


char MetaStrategy::act() {
    size_t size = log.opponentNumber();
    for (size_t i = 0; i < size; i++) {
        if (log.isCooperating(i)) {
            countCoop++;
        }
        if (log.isDefecting(i)) {
            countDefect++;
        }
    }
    if (countCoop == countDefect) {
        return strategyList[0]->act();
    } else if (countCoop > countDefect) {
        return strategyList[1]->act();
    } else {
        return strategyList[2]->act();
    }
}


MetaStrategy::~MetaStrategy() {
    for (auto it = strategyList.begin(); it != strategyList.end(); it++) {
        delete *it;
    }
}