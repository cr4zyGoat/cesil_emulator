#include "processthreadsapi.h"

Processthreadsapi::Processthreadsapi() {
    this->add_function("ExitProcess",
        [](){
            return arguments_t {
                new FunctionArgument("uExitCode", FunctionArgument::NUMBER)
            };
        },
        [](arguments_t args) {
            return results_t {
                new FunctionResult(args.at(0)->get_value(), FunctionResult::EXIT_PROCESS)
            };
        }
    );
};