#include "emulator.h"
#include "utilities.h"

Emulator::Emulator(std::string filename)
{
    this->emulation_finished = false;
    
    std::string command = "radare2 -q0 " + filename;
    this->r2 = r2pipe_open(command.c_str());
    this->setup_radare();
    this->setup_relocation_table();
}

void Emulator::setup_radare()
{
    this->r2cmd("aaaa");
    this->r2cmd("e io.cache=1");
    this->r2cmd("aeim");
}

void Emulator::setup_relocation_table()
{
    Json::Value relocations = this->r2cmdj("irj");
    this->relocation_table = new RelocationTable(relocations);
}

char* Emulator::r2cmd(const char *command)
{
    return r2pipe_cmd(this->r2, command);
}

Json::Value Emulator::r2cmdj(const char *command)
{
    char *str = this->r2cmd(command);
    return UTILITIES_H::string_to_json(str);
}

Instruction* Emulator::get_current_instruction()
{
    Json::Value data = this->r2cmdj("pdj 1 @eip")[0];
    return new Instruction(data);
}

void Emulator::run()
{
    printf("%s\n", this->r2cmd("i"));
    Json::Value instructions = this->r2cmdj("pdfj");
    this->current_instruction = this->get_current_instruction();
    printf("Result name: %s\n", instructions.get("name", "name").asCString());
    printf("First instruction: %s\n", this->current_instruction->get_disasm().c_str());
    printf("First offset: %lu\n", this->current_instruction->get_offset());
}