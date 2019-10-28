#ifndef EMULATOR_H
#define EMULATOR_H

#include <json/json.h>
#include <r_socket.h>

#include "instruction.h"
#include "relocation.h"

class Emulator
{
private:
    R2Pipe *r2;
    Instruction *current_instruction;
    RelocationTable *relocation_table;
    bool emulation_finished;

    void setup_radare();
    void setup_relocation_table();
    char* r2cmd(const char *command);
    Json::Value r2cmdj(const char *command);
    Instruction* get_current_instruction();
    
public:
    Emulator(std::string filename);
    void run();
    
};

#endif