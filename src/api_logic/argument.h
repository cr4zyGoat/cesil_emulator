#ifndef API_LOGIC_ARGUMENT_H
#define API_LOGIC_ARGUMENT_H

#include <string>

class FunctionArgument
{
private:
    unsigned long address;
    std::string name;
    std::string value;
    int type;


public:
    static const int STRING;
    static const int NUMBER;
    static const int ADDRESS;
    static const int UNDEFINED;

    FunctionArgument(const std::string name, const int type);
    unsigned long get_address();
    void set_address(unsigned long address);
    std::string get_name();
    std::string get_value();
    void set_value(std::string value);
    int get_type();

};

#endif