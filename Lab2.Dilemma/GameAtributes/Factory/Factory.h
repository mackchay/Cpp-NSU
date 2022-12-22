#ifndef LAB2_DILEMMA_FACTORY_H
#define LAB2_DILEMMA_FACTORY_H

#include <map>

template<class ID, class Base, class ...Args>
class Factory {
private:
    typedef Base *(*creator)(Args...);

    std::map<ID, creator> ObjectsMap;
    template<class Derived>
    static Base* create(Args...args) {
        return new Derived(args...);
    }

public:
    Factory() = default;

    template<class Derived>
    void add(ID id) {
        ObjectsMap[id] = &create<Derived>;
    }

    creator get(ID id) {
        return ObjectsMap[id];
    }

    bool contains(ID id) {
        if (ObjectsMap.contains(id))
            return true;
        return false;
    }
};


#endif //LAB2_DILEMMA_FACTORY_H
