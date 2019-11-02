#ifndef API_BASE_H
#define API_BASE_H

#include <string>
#include <vector>
#include <map>

#include "interface.h"

class ApiBase: public IApi 
{
private:
    std::map<std::string, IApiFunction*> functions;
    
public:
    ApiBase();

    bool contains_function(const std::string function_name);
    std::vector<FunctionArgument> get_function_arguments(const std::string function_name);
    std::vector<FunctionResult> emulate_function(const std::string function_name, const std::vector<FunctionArgument> arguments);

};

#endif