#include "argument.h"

FunctionArgument::FunctionArgument(const std::string name, const int type) {
    this->name = name;
    this->type = type;
};

unsigned long FunctionArgument::get_address() {
    return this->address;
};

void FunctionArgument::set_address(unsigned long address) {
    this->address = address;
};

std::string FunctionArgument::get_name() {
    return this->name;
};

std::string FunctionArgument::get_value() {
    return this->value;
};

void FunctionArgument::set_value(std::string value) {
    this->value = value;
};

int FunctionArgument::get_type() {
    return this->type;
};