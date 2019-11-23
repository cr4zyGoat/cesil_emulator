#include "apibase.h"

ApiBase::ApiBase() {};

void ApiBase::add_function(const std::string name, args_func args_function, emul_func emul_function) {
    ApiFunction *function = new ApiFunction {name, args_function, emul_function};
    this->functions.insert(std::pair<std::string, ApiFunction*>(name, function));
};

bool ApiBase::contains_function(const std::string function_name) {
    return this->functions.count(function_name) > 0;
};

arguments_t ApiBase::get_function_arguments(const std::string function_name) {
    return this->functions.at(function_name)->get_arguments();
};

results_t ApiBase::emulate_function(const std::string function_name, const arguments_t arguments) {
    return this->functions.at(function_name)->emulate(arguments);
};