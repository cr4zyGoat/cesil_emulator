#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>

#include "radare.h"
#include "instruction.h"
#include "relocation.h"
#include "api/interface.h"

class Emulator
{
private:
    Radare *r2;
    IApi *apis;
    Instruction *current_instruction;
    RelocationTable *relocations_table;
    bool emulation_finished;

public:
    Emulator(Radare *r2, IApi *apis);
    void run();
    
};

#endif