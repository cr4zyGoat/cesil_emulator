#include "apibase.h"

ApiBase::ApiBase() {};

void ApiBase::add_function(const std::string function_name, IApiFunction *function) {
    this->functions.insert(std::pair<std::string, IApiFunction*>(function_name, function));
};

bool ApiBase::contains_function(const std::string function_name) {
    return this->functions.count(function_name) > 0;
};

std::vector<FunctionArgument*> ApiBase::get_function_arguments(const std::string function_name) {
    return this->functions.at(function_name)->get_function_arguments();
};

std::vector<FunctionResult*> ApiBase::emulate_function(const std::string function_name,const std::vector<FunctionArgument*> arguments) {
    return this->functions.at(function_name)->emulate_function(arguments);
}