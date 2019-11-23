#include "emulator.h"

Emulator::Emulator(Radare *r2, IApi *apis) {
    this->r2 = r2;
    this->apis = apis;
    this->setup();
};

void Emulator::setup() {
    this->relocations_table = r2->get_relocations_table();
    this->emulation_finished = false;
};

void Emulator::run() {
    // Testing
    this->current_instruction = this->r2->get_current_instruction();
    printf("First instruction: %s\n", this->current_instruction->get_disasm().c_str());
    printf("First offset: %lu\n", this->current_instruction->get_offset());
    printf("EIP register value (hex): %s\n", this->r2->get_register_value("eip"));
    printf("EIP register value (dec): %ul\n", UTILITIES_H::hex2ulong(this->r2->get_register_value("eip")));
    printf("Seek address value: %s\n", this->r2->get_address_value("0x00401260"));
    printf("\n");

    while (!this->emulation_finished) {
        this->current_instruction = this->r2->get_current_instruction();
        this->emulation_step();

        if (this->current_instruction->is_call()) printf("%s\n", this->current_instruction->get_disasm().c_str()); // Testing
    }
};

void Emulator::fill_function_arguments(const arguments_t arguments) {
    unsigned long address = UTILITIES_H::hex2ulong(this->r2->get_register_value("esp"));
    std::string value;
    for (FunctionArgument *argument : arguments) {
        address += 4;
        switch (argument->get_type()) {
        case FunctionArgument::STRING:
            value = this->r2->get_address_string(address);
            break;
        default:
            value = this->r2->get_address_value(address);
        }
        argument->set_value(value);
    }
};

void Emulator::emulate_function(const std::string function_name) {
    arguments_t arguments;
    results_t results;
    if (this->apis->contains_function(function_name)) {
        arguments = this->apis->get_function_arguments(function_name);
        this->fill_function_arguments(arguments);
        results = this->apis->emulate_function(function_name, arguments);
    }
    this->r2->execute_return();
};

void Emulator::emulation_step() {
    this->r2->emulation_step();
    unsigned long address = this->r2->get_current_address();

    if (this->relocations_table->contains_vaddr(address)) {
        std::string function = this->relocations_table->get_relocation_by_vaddr(address)->get_name();
        this->emulate_function(function);
        printf("Emulation function: %s\n", function.c_str()); // Testing
    }
};