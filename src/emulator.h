#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>

#include "radare.h"
#include "instruction.h"
#include "relocation.h"

class Emulator
{
private:
    Radare *r2;
    Instruction *current_instruction;
    RelocationTable *relocations_table;
    bool emulation_finished;

public:
    Emulator(Radare *r2);
    void run();
    
};

#endif