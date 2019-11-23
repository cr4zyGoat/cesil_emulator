#include "winbase.h"

Atom::Atom(const unsigned int key, const std::string value) {
    this->key = key;
    this->value = value;
    this->count = 1;
};

unsigned int Atom::get_key() { return this->key; };
std::string Atom::get_value() { return this->value; };
unsigned int Atom::get_count() { return this->count; };

void Atom::increment_count() { this->count++; };
void Atom::decrement_count() { this->count--; };

AtomTable::AtomTable() {
    this->count = 0;
};

Atom* AtomTable::find_atom_by_key(const unsigned int key) {
    return this->atoms_table.at(key);
};

Atom* AtomTable::find_atom_by_value(const std::string value) {
    for (std::pair<unsigned int, Atom*> element : this->atoms_table) {
        if (element.second->get_value() == value) {
            return element.second;
        }
    };
    return nullptr;
};

Atom* AtomTable::add_atom(const std::string value) {
    Atom *atom = this->find_atom_by_value(value);
    if (atom == nullptr) {
        this->count++;
        atom = new Atom(this->count, value);
        this->atoms_table.insert(std::pair<unsigned int, Atom*> (this->count, atom));
    } else {
        atom->increment_count();
    }
    return atom;
};

void AtomTable::remove_atom(const unsigned key) {
    this->atoms_table.erase(key);
};