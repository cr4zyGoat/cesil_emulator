#include "instruction.h"

Instruction::Instruction(Json::Value data) 
{
    this->disasm = data.get("disasm", "invalid").asString();
    this->opcode = data.get("opcode", "invalid").asString();
    this->esil = data.get("esil", "invalid").asString();
    this->offset = data.get("offset", 0).asLargestUInt();
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