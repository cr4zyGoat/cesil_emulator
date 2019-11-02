#include "result.h"

const int FunctionResult::BYTES = 0;
const int FunctionResult::NUMBER = 1;
const int FunctionResult::EXIT_PROCESS = 99;

FunctionResult::FunctionResult(std::string target, const std::string value, const int type, bool to_reference) {
    this->target = target;
    this->value = value;
    this->type = type;
    this->to_reference = to_reference;
};

std::string FunctionResult::get_target() {
    return this->target;   
};

std::string FunctionResult::get_value() {
    return this->value;
};

int FunctionResult::get_type() {
    return this->type;
};

bool FunctionResult::is_reference() {
    return this->to_reference;
};