#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>
#include <json/json.h>
#include <r_socket.h>

using namespace std;

class Emulator
{
private:
    R2Pipe *r2;

    void setup();
    char* r2cmd(const char *command);
    Json::Value r2cmdj(const char *command);
    
public:
    Emulator(string filename);
    void run();
    
};

#endif