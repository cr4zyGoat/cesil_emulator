#ifndef IAPI_H
#define IAPI_H

#include <string>
#include <vector>

#include "argument.h"
#include "result.h"

class IApi
{
public:
    virtual bool contains_function(std::string function_name) = 0;
    virtual std::vector<FunctionArgument> get_function_arguments(std::string function_name) = 0;
    virtual std::vector<FunctionResult> emulate_function(std::string function_name, std::vector<FunctionArgument> arguments) = 0;
};

#endif