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

Json::Value Radare::get_current_instruction() {
    return this->r2cmdj("pdj 1 @eip")[0];
};

Json::Value Radare::get_relocations() {
    return this->r2cmdj("irj");
};

char* Radare::get_register(std::string reg) {
    return this->r2cmd(("aer " + reg).c_str());
};

void Radare::execute_return() {
    this->r2cmd("ae esp,[4],eip,=,4,esp,+=");
    std::string eip = this->get_register("eip");
    this->r2cmd(("aepc " + eip).c_str());
};