#ifndef API_RESULT_H
#define API_RESULT_H

#include <string>

class FunctionResult
{
private:
    std::string target;
    int type;
    std::string value;
    bool to_reference;


public:
    static const int BYTES = 0;
    static const int NUMBER = 1;
    static const int EXIT_PROCESS = 99;

    FunctionResult(std::string target, const int type, const std::string value, bool to_reference);
    std::string get_target();
    int get_type();
    auto get_value();
    bool is_reference();

};

#endif