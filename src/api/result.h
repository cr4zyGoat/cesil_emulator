#ifndef API_RESULT_H
#define API_RESULT_H

#include <string>

class FunctionResult
{
private:
    std::string target;
    std::string value;
    int type;
    bool to_reference;


public:
    static const int BYTES;
    static const int NUMBER;
    static const int EXIT_PROCESS;

    FunctionResult(std::string target, const std::string value, const int type, bool to_reference);
    std::string get_target();
    std::string get_value();
    int get_type();
    bool is_reference();

};

#endif