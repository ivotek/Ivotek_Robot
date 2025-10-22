#ifndef TESTABLE_H
#define TESTABLE_H

class Testable {
public:
    virtual ~Testable() = default;
    virtual void test() = 0;  // metodo puro virtuale
};

#endif

