#ifndef API_ARGUMENT_H
#define API_ARGUMENT_H

#include <string>

class FunctionArgument
{
private:
    unsigned long address;
    std::string name;
    int type;
    std::string value;


public:
    static const int STRING = 0;
    static const int NUMBER = 1;
    static const int ADDRESS = 2;
    static const int UNDEFINED = 99;

    FunctionArgument(const unsigned long address, const std::string name, const int type);
    unsigned long get_address();
    std::string get_name();
    int get_type();
    auto get_value();
    void set_value(std::string value);

};

#endif