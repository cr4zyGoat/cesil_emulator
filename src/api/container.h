#ifndef API_CONTAINER_H
#define API_CONTAINER_H

#include <string>
#include <vector>

#include "interface.h"

#define NOT_DEFINED_ARGUMENT_EXCEPTION -99

class Container: public IApi
{
private:
    std::vector<IApi*> apis;
    
public:
    Container();
    void load_api(IApi *api);

    bool contains_function(const std::string function_name);
    std::vector<FunctionArgument> get_function_arguments(const std::string function_name);
    std::vector<FunctionResult> emulate_function(const std::string function_name, const std::vector<FunctionArgument> arguments);

};

#endif