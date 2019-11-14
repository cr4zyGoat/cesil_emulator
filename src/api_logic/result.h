#ifndef API_LOGIC_RESULT_H
#define API_LOGIC_RESULT_H

#include <string>

class FunctionResult
{
private:
    std::string target;
    std::string value;
    int type;
    bool to_reference;


public:
    enum {
        BYTES = 0,
        NUMBER = 1,
        EXIT_PROCESS = 99
    };
    
    FunctionResult(std::string target, const std::string value, const int type, bool to_reference);
    FunctionResult(const std::string value, const int type);
    std::string get_target();
    std::string get_value();
    int get_type();
    bool is_reference();

};

#endif