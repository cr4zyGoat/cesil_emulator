#include "container.h"

Container::Container() {};

void Container::load_api(IApi *api) {
    this->apis.push_back(api);
};

bool Container::contains_function(const std::string function_name) {
    for (IApi *api : this->apis) {
        if (api->contains_function(function_name)) 
            return true;
    }
    return false;
};

arguments_t Container::get_function_arguments(const std::string function_name) {
    for (IApi *api : this->apis) {
        if (api->contains_function(function_name)) 
            return api->get_function_arguments(function_name);
    }
    throw NOT_DEFINED_ARGUMENT_EXCEPTION;
};

results_t Container::emulate_function(const std::string function_name, const arguments_t arguments) {
    for (IApi *api : this->apis) {
        if (api->contains_function(function_name))
            return api->emulate_function(function_name, arguments);
    }
    throw NOT_DEFINED_ARGUMENT_EXCEPTION;
};