#ifndef API_IMPLEMENTATIONS_WINBASE_H
#define API_IMPLEMENTATIONS_WINBASE_H

#include <map>

#include "api_logic/apibase.h"

class Atom
{
private:
    unsigned int key;
    std::string value;
    unsigned int count;

public:
    Atom(const unsigned int key, const std::string value);
    unsigned int get_key();
    std::string get_value();
    unsigned int get_count();
    void increment_count();
    void decrement_count();

};

class AtomTable
{
private:
    unsigned int count;
    std::map<unsigned int, Atom*> atoms_table;

public:
    AtomTable();
    Atom* find_atom_by_key(const unsigned int key);
    Atom* find_atom_by_value(const std::string value);
    Atom* add_atom(const std::string value);
    void remove_atom(const unsigned int key);

};

class Winbase: public ApiBase
{
private:
    AtomTable *atoms_table;

public:
    Winbase();

};

#endif