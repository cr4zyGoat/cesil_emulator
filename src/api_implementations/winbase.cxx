#include "winbase.h"

Winbase::Winbase() {
    this->add_function("FindAtomA",
        [](){
            return arguments_t {
                new FunctionArgument("lpString", FunctionArgument::STRING)
            };
        },
        [*this](arguments_t args) {
            Atom *atom = this->atoms_table->find_atom_by_value(args.at(0)->get_value());
            return results_t {
                new FunctionResult(std::to_string(atom->get_key()), FunctionResult::NUMBER)
            };
        }
    );
};