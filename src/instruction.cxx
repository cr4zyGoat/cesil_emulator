#include "instruction.h"

const std::string Instruction::INVALID_INSTRUCTION = "INVALID_INSTRUCTION";
const unsigned long Instruction::INVALID_ADDRESS = 0;

Instruction::Instruction(const Json::Value data) {
    this->disasm = data.get("disasm", Instruction::INVALID_INSTRUCTION).asString();
    this->opcode = data.get("opcode", Instruction::INVALID_INSTRUCTION).asString();
    this->esil = data.get("esil", Instruction::INVALID_INSTRUCTION).asString();
    this->offset = data.get("offset", Instruction::INVALID_ADDRESS).asLargestUInt();
};

std::string Instruction::get_disasm() {
    return this->disasm;
};

std::string Instruction::get_opcode() {
    return this->opcode;
};

std::string Instruction::get_esil() {
    return this->esil;
};

unsigned long Instruction::get_offset() {
    return this->offset;
};

std::string Instruction::get_operation() {
    return this->opcode.substr(0, this->opcode.find(' '));
};

bool Instruction::is_call() {
    return this->get_operation() == "call";
};