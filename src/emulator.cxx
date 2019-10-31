#include "emulator.h"

Emulator::Emulator(Radare *r2)
{
    this->r2 = r2;
    this->relocations_table = new RelocationTable(r2->get_relocations());
    this->emulation_finished = false;
}

void Emulator::run()
{
    // Testing
    this->current_instruction = new Instruction(this->r2->get_current_instruction());
    printf("First instruction: %s\n", this->current_instruction->get_disasm().c_str());
    printf("First offset: %lu\n", this->current_instruction->get_offset());
}