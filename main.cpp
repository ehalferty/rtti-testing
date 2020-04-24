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

int main() {
    XyFoo xyFoo;
    std::cout << "Hello, World!" << xyFoo.rtti->name << std::endl;
    return 0;
}
