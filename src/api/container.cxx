#include "container.h"

Container::Container() {};

void Container::load_api(IApi *api) {
    this->apis.insert(this->apis.end(), api);
};

bool Container::contains_function(const std::string function_name) {
    for (auto api : this->apis) {
        if (api->contains_function(function_name)) 
            return true;
    }
    return false;
};

std::vector<FunctionArgument> Container::get_function_arguments(const std::string function_name) {
    for (auto api : this->apis) {
        if (api->contains_function(function_name)) 
            return api->get_function_arguments(function_name);
    }
    throw NOT_DEFINED_ARGUMENT_EXCEPTION;
};

std::vector<FunctionResult> Container::emulate_function(const std::string function_name, const std::vector<FunctionArgument> arguments) {
    for (auto api : this->apis) {
        if (api->contains_function(function_name))
            return api->emulate_function(function_name, arguments);
    }
    throw NOT_DEFINED_ARGUMENT_EXCEPTION;
};