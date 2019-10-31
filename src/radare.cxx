#include "radare.h"

Radare::Radare(std::string filename)
{
    std::string command = "radare2 -q0 " + filename;
    this->r2 = r2pipe_open(command.c_str());
    this->setup();

    // Testing
    printf("%s\n", this->r2cmd("i"));
    Json::Value instructions = this->r2cmdj("pdfj");
    printf("Result name: %s\n", instructions.get("name", "name").asCString());
}

void Radare::setup()
{
    this->r2cmd("aaaa");
    this->r2cmd("e io.cache=1");
    this->r2cmd("aeim");
}

char* Radare::r2cmd(const char *command)
{
    return r2pipe_cmd(this->r2, command);
}

Json::Value Radare::r2cmdj(const char *command)
{
    char *str = this->r2cmd(command);
    return UTILITIES_H::string_to_json(str);
}

Json::Value Radare::get_current_instruction()
{
    return this->r2cmdj("pdj 1 @eip")[0];
}

Json::Value Radare::get_relocations()
{
    return this->r2cmdj("irj");
}