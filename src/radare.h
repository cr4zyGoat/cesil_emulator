#ifndef RADARE_H
#define RADARE_H

#include <string>
#include <json/json.h>
#include <r_socket.h>

#include "utilities.h"

class Radare
{
private:
    R2Pipe *r2;

    void setup();
    char* r2cmd(const char *command);
    Json::Value r2cmdj(const char *command);
    
public:
    Radare(const std::string filename);
    Json::Value get_current_instruction();
    Json::Value get_relocations();
    char* get_register(const std::string reg);
    void execute_return();

};

#endif