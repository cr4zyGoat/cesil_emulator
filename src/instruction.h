#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <json/json.h>

#define INVALID_INSTRUCTION "INVALID"
#define INVALID_ADDRESS 0

class Instruction
{
private:
    std::string disasm;
    std::string opcode;
    std::string esil;
    unsigned long offset;

public:
    Instruction(const Json::Value data);
    std::string get_disasm();
    std::string get_opcode();
    std::string get_esil();
    unsigned long get_offset();

};

#endif