#ifndef RELOCATION_H
#define RELOCATION_H

#include <string>
#include <json/json.h>

class Relocation
{
private:
    std::string name;
    std::string type;
    unsigned long vaddr;

public:
    static const std::string INVALID_RELOCATION;
    static const unsigned long INVALID_ADDRESS;

    Relocation(const Json::Value data);
    std::string get_name();
    std::string get_type();
    unsigned long get_vaddr();

};

class RelocationTable
{
private:
    std::vector<Relocation*> relocations;

public:
    RelocationTable(const Json::Value data);

};

#endif