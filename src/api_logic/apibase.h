#ifndef API_LOGIC_APIBASE_H
#define API_LOGIC_APIBASE_H

#include <string>
#include <vector>
#include <map>

#include "interface.h"

class ApiBase: public IApi
{
protected:
    std::map<std::string, ApiFunction*> functions;

    void add_function(const std::string name, args_func args_function, emul_func emul_function);
    
public:
    ApiBase();

    bool contains_function(const std::string function_name);
    arguments_t get_function_arguments(const std::string function_name);
    results_t emulate_function(const std::string function_name, const arguments_t arguments);

};

#endif