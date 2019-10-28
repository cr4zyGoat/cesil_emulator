#include "instruction.h"

Instruction::Instruction(const Json::Value data) 
{
    this->disasm = data.get("disasm", INVALID_INSTRUCTION).asString();
    this->opcode = data.get("opcode", INVALID_INSTRUCTION).asString();
    this->esil = data.get("esil", INVALID_INSTRUCTION).asString();
    this->offset = data.get("offset", INVALID_ADDRESS).asLargestUInt();
}

std::string Instruction::get_disasm()
{
    return this->disasm;
}

std::string Instruction::get_opcode()
{
    return this->opcode;
}

std::string Instruction::get_esil()
{
    return this->esil;
}

unsigned long Instruction::get_offset()
{
    return this->offset;
}