#include <iostream>

class XyRTTI {
public:
    XyRTTI(std::string const name_, XyRTTI const * base_) {
        name.assign(name_);
        base = base_;
    }
    std::string name;
    XyRTTI const * base;
};

class XyFoo {
public:
    static inline XyRTTI * rtti = new XyRTTI( "XyFoo", nullptr);
};

class XyFooFoo {
public:
    static inline XyRTTI * rtti = new XyRTTI("XyFooFoo", XyFoo::rtti);
};

int main() {
    XyFoo xyFoo;
    XyFooFoo xyFooFoo;
    std::cout << "Class of xyFoo: " << xyFoo.rtti->name << std::endl <<
        "Class of xyFooFoo: "<< xyFooFoo.rtti->name << std::endl;
    return 0;
}
