#include "emulator.h"

Emulator::Emulator(Radare *r2, IApi *apis) {
    this->r2 = r2;
    this->apis = apis;
    this->relocations_table = new RelocationTable(r2->get_relocations());
    this->emulation_finished = false;
};

void Emulator::run() {
    // Testing
    this->current_instruction = new Instruction(this->r2->get_current_instruction());
    printf("First instruction: %s\n", this->current_instruction->get_disasm().c_str());
    printf("First offset: %lu\n", this->current_instruction->get_offset());
    printf("EIP register value (hex): %s\n", this->r2->get_register("eip"));
    printf("EIP register value (dec): %ul\n", UTILITIES_H::hex2ulong(this->r2->get_register("eip")));
};

void Emulator::emulate_function(const std::string function_name) {
    std::vector<FunctionArgument*> arguments;
    std::vector<FunctionResult*> results;
    if (this->apis->contains_function(function_name)) {
        arguments = this->apis->get_function_arguments(function_name);
        //this->fill_function_arguments(arguments);
        results = this->apis->emulate_function(function_name, arguments);
    }
    this->r2->execute_return();
};