#ifndef API_INTERFACE_H
#define API_INTERFACE_H

#include <string>
#include <vector>

#include "argument.h"
#include "result.h"

class IApi
{
public:
    virtual bool contains_function(const std::string function_name) = 0;
    virtual std::vector<FunctionArgument> get_function_arguments(const std::string function_name) = 0;
    virtual std::vector<FunctionResult> emulate_function(const std::string function_name, const std::vector<FunctionArgument> arguments) = 0;

};

class IApiFunction
{
public:
    virtual std::vector<FunctionArgument> get_function_arguments() = 0;
    virtual std::vector<FunctionResult> emulate_function(const std::vector<FunctionArgument> arguments) = 0;

};

#endif