#ifndef EMULATOR_H
#define EMULATOR_H

#include <string>
#include <r_socket.h>

using namespace std;

class Emulator
{
private:
    R2Pipe *r2;

    void r2cmd(const char *command);
    
public:
    Emulator(string filename);
    void run();
    
};

#endif