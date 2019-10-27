#include "emulator.h"
#include "utilities.h"

Emulator::Emulator(string filename)
{
    string command = "radare2 -q0 " + filename;
    this->r2 = r2pipe_open(command.c_str());
    this->setup();
}

void Emulator::setup()
{
    this->r2cmd("aaaa");
    this->r2cmd("e io.cache=1");
    this->r2cmd("aeim");
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

void Emulator::run()
{
    printf("%s\n", this->r2cmd("i"));
    Json::Value instructions = this->r2cmdj("pdfj");
    printf("Result name: %s\n", instructions.get("jhfeuishfisuehfsueifh", "name").asCString());
}