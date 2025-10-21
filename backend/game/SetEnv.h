#ifndef SETENV
#define SETENV

#include <cstdlib>

class SetEnv {
    public:
        SetEnv() {
            setenv("MY_VAR", "HelloWorld", 1);
        };
};

#endif // SETENV