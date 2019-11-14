#include "radare.h"

Radare::Radare(std::string filename) {
    this->r2 = r2pipe_open(("radare2 -q0 " + filename).c_str());
    this->setup();

    // Testing
    printf("%s\n", this->r2cmd("i~file"));
    Json::Value instructions = this->r2cmdj("pdfj");
    printf("Result name: %s\n", instructions.get("name", "name").asCString());
};

void Radare::setup() {
    this->r2cmd("aaa");
    this->r2cmd("e io.cache=1");
    this->r2cmd("aeim");
};

char* Radare::r2cmd(const char *command) {
    std::string result = r2pipe_cmd(this->r2, command);
    result = UTILITIES_H::strip(result);
    return strdup(result.c_str());
};

Json::Value Radare::r2cmdj(const char *command) {
    char *str = this->r2cmd(command);
    return UTILITIES_H::string2json(str);
};

RelocationTable* Radare::get_relocations_table() {
    return new RelocationTable(this->r2cmdj("irj"));
};

Instruction* Radare::get_current_instruction() {
    return new Instruction(this->r2cmdj("pdj 1 @eip")[0]);
};

unsigned long Radare::get_current_address() {
    return this->get_current_instruction()->get_offset();
};

char* Radare::get_register_value(const std::string reg) {
    return this->r2cmd(("aer " + reg).c_str());
};

char* Radare::get_address_value(const std::string address) {
    char *result = this->r2cmd(("pf x @" + address).c_str());
    return std::strrchr(result, ' ') + 1;
};

char* Radare::get_address_value(const unsigned long address) {
    return this->get_address_value(std::to_string(address));
};

char* Radare::get_address_string(const std::string address) {
    return this->r2cmd(("ps @" + address).c_str());
};

char* Radare::get_address_string(const unsigned long address) {
    return this->get_address_string(std::to_string(address));
};

void Radare::execute_return() {
    this->r2cmd("ae esp,[4],eip,=,4,esp,+=");
    std::string eip = this->get_register_value("eip");
    this->r2cmd(("aepc " + eip).c_str());
};

void Radare::emulation_step() {
    this->r2cmd("aes");
};