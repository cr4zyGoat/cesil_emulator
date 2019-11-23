#ifndef API_LOGIC_INTERFACE_H
#define API_LOGIC_INTERFACE_H

#include <vector>
#include <string>
#include <functional>

#include "argument.h"
#include "result.h"

typedef std::vector<FunctionArgument*> arguments_t;
typedef std::vector<FunctionResult*> results_t;
typedef std::function<arguments_t()> args_func;
typedef std::function<results_t(arguments_t)> emul_func;

class IApi
{
public:
    virtual bool contains_function(const std::string function_name) = 0;
    virtual arguments_t get_function_arguments(const std::string function_name) = 0;
    virtual results_t emulate_function(const std::string function_name, const arguments_t arguments) = 0;

};

struct ApiFunction {
    std::string name;
    args_func get_arguments;
    emul_func emulate;
};

#endif