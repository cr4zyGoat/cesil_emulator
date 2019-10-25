#include "emulator.h"

Emulator::Emulator(string filename)
{
    string command = "radare2 -q0 " + filename;
    this->r2 = r2pipe_open(command.c_str());
}

void Emulator::r2cmd(const char *command)
{
    char *msg = r2pipe_cmd(this->r2, command);
    if (msg) {
        printf ("%s\n", msg);
        free (msg);
    }
}

void Emulator::run()
{
    this->r2cmd("i");
}