#include "argument.h"

const int FunctionArgument::STRING = 0;
const int FunctionArgument::NUMBER = 1;
const int FunctionArgument::ADDRESS = 2;
const int FunctionArgument::UNDEFINED = 99;

FunctionArgument::FunctionArgument(const unsigned long address, const std::string name, const int type) {
    this->address = address;
    this->name = name;
    this->type = type;
};

unsigned long FunctionArgument::get_address() {
    return this->address;
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