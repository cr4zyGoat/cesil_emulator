#ifndef API_ARGUMENT_H
#define API_ARGUMENT_H

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

    FunctionArgument(const unsigned long address, const std::string name, const int type);
    unsigned long get_address();
    std::string get_name();
    std::string get_value();
    void set_value(std::string value);
    int get_type();

};

#endif