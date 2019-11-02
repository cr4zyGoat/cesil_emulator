#include "relocation.h"

const std::string Relocation::INVALID_RELOCATION = "INVALID_RELOCATION";
const unsigned long Relocation::INVALID_ADDRESS = 0;

Relocation::Relocation(const Json::Value data) {
    this->name = data.get("name", Relocation::INVALID_RELOCATION).asString();
    this->type = data.get("type", Relocation::INVALID_RELOCATION).asString();
    this->vaddr = data.get("vaddr", Relocation::INVALID_ADDRESS).asLargestUInt();
};

std::string Relocation::get_name() {
    return this->name;
};

std::string Relocation::get_type() {
    return this->type;
};

unsigned long Relocation::get_vaddr() {
    return this->vaddr;
};

RelocationTable::RelocationTable(const Json::Value data) {
    Relocation *relocation;
    for (Json::Value jrelocation : data) {
        relocation = new Relocation(jrelocation); 
        this->relocations.insert(this->relocations.end(), relocation);
    }
};