#ifndef M_OPTION
#define M_OPTION

class MenuOption {
    public:
        virtual void execute() = 0;
        ~MenuOption() = default;
};

#endif // M_OPTION