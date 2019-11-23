#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>

#include "radare.h"
#include "instruction.h"
#include "relocation.h"
#include "api_logic/interface.h"

class Emulator
{
private:
    Radare *r2;
    IApi *apis;
    Instruction *current_instruction;
    RelocationTable *relocations_table;
    bool emulation_finished;

    void setup();
    void emulation_step();
    void emulate_function(const std::string function_name);
    void fill_function_arguments(const arguments_t arguments);

public:
    Emulator(Radare *r2, IApi *apis);
    void run();
    
};

#endif