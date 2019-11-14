#ifndef RADARE_H
#define RADARE_H

#include <string>
#include <json/json.h>
#include <r_socket.h>

#include "instruction.h"
#include "relocation.h"
#include "utilities.h"

class Radare
{
private:
    R2Pipe *r2;

    void setup();
    char* r2cmd(const char *command);
    Json::Value r2cmdj(const char *command);
    
public:
    Radare(const std::string filename);
    RelocationTable* get_relocations_table();
    Instruction* get_current_instruction();
    unsigned long get_current_address();
    char* get_register_value(const std::string reg);
    char* get_address_value(const std::string address);
    char* get_address_value(const unsigned long address);
    char* get_address_string(const std::string address);
    char* get_address_string(const unsigned long address);
    void emulation_step();
    void execute_return();

};

#endif