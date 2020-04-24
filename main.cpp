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

class XyBar {
public:
    static inline XyRTTI * rtti = new XyRTTI("XyBar", nullptr);
};

bool XyIsKindOf(XyRTTI const * item, XyRTTI const * other) {
    XyRTTI const * next = item;
    while (next) {
        if (next == other) {
            return true;
        }
        next = next->base;
    }
    return false;
}

int main() {
    XyFoo xyFoo;
    XyFooFoo xyFooFoo;
    XyBar xyBar;
    std::cout << "Class of xyFoo: " << xyFoo.rtti->name << std::endl
            << "Class of xyFooFoo: "<< xyFooFoo.rtti->name << std::endl
            << "Class of xyBar: "<< xyBar.rtti->name << std::endl
            << "xyFooFoo IS" << (XyIsKindOf(xyFooFoo.rtti, xyFoo.rtti) ? "" : " NOT")
            << " a type of xyFoo" << std::endl
            << "xyBar IS" << (XyIsKindOf(xyBar.rtti, xyFoo.rtti) ? "" : " NOT")
            << " a type of xyFoo" << std::endl
        ;
    return 0;
}
