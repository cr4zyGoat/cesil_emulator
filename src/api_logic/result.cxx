#include "result.h"

FunctionResult::FunctionResult(std::string target, const std::string value, const int type, bool to_reference) {
    this->target = target;
    this->value = value;
    this->type = type;
    this->to_reference = to_reference;
};

FunctionResult::FunctionResult(const std::string value, const int type) {
    FunctionResult("eax", value, type, false);
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