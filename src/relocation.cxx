#include "relocation.h"

Relocation::Relocation(const Json::Value data) {
    this->name = data.get("name", INVALID_RELOCATION).asString();
    this->type = data.get("type", INVALID_RELOCATION).asString();
    this->vaddr = data.get("vaddr", INVALID_ADDRESS).asLargestUInt();
}

std::string Relocation::get_name() {
    return this->name;
}

std::string Relocation::get_type() {
    return this->type;
}

unsigned long Relocation::get_vaddr() {
    return this->vaddr;
}

RelocationTable::RelocationTable(const Json::Value data) {
    Relocation *relocation;
    for (Json::Value jrelocation : data) {
        relocation = new Relocation(jrelocation); 
        this->relocations.insert(this->relocations.end(), relocation);
    }
}