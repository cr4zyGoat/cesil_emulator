#ifndef RELOCATION_H
#define RELOCATION_H

#include <json/json.h>

#define INVALID_RELOCATION "INVALID"
#define INVALID_ADDRESS 0

class Relocation
{
private:
    std::string name;
    std::string type;
    unsigned long vaddr;

public:
    Relocation(const Json::Value data);
    std::string get_name();
    std::string get_type();
    unsigned long get_vaddr();

};

class RelocationTable
{
private:
    std::vector<Relocation> relocations;

public:
    RelocationTable(const Json::Value data);

};

#endif