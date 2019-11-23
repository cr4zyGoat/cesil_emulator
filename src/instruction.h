#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <json/json.h>

class Instruction
{
private:
    std::string disasm;
    std::string opcode;
    std::string esil;
    unsigned long offset;

    std::string get_operation();

public:
    static const std::string INVALID_INSTRUCTION;
    static const unsigned long INVALID_ADDRESS;

    Instruction(const Json::Value data);
    std::string get_disasm();
    std::string get_opcode();
    std::string get_esil();
    unsigned long get_offset();
    bool is_call();

};

#endif